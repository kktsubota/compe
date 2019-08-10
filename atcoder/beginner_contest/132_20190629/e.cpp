#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <utility>

using namespace std;

int main(int argc, char const *argv[])
{
    int N, M;
    cin >> N >> M;
    vector<int> us(M), vs(M);
    int S, T;
    for (int i = 0; i < M; i++) {
        cin >> us[i] >> vs[i];
        us[i] -= 1;
        vs[i] -= 1;
    }
    cin >> S >> T;
    S -= 1;
    T -= 1;

    unordered_map<int, vector<int>> fake_connected_nodes;
    for (int i = 0; i < M; i++) {
        fake_connected_nodes[us[i]].push_back(vs[i]);
    }

    unordered_map<int, vector<int>> real_connected_nodes;
    for (int node = 0; node < N; node++) {
        unordered_set<int> accessed_2nd;
        unordered_set<int> accessed_3rd;

        vector<int> nodes_1st = fake_connected_nodes[node];
        for (auto node_1st: nodes_1st) {
            vector<int> nodes_2nd = fake_connected_nodes[node_1st];
            for (auto node_2nd: nodes_2nd) {
                if (accessed_2nd.find(node_2nd) != accessed_2nd.find(node_2nd)) {
                    continue;
                }
                accessed_2nd.insert(node_2nd);
                vector<int> nodes_3rd = fake_connected_nodes[node_2nd];
                for (auto node_3rd: nodes_3rd) {
                    if (accessed_3rd.find(node_3rd) != accessed_3rd.find(node_3rd)) {
                        continue;
                    }
                    accessed_3rd.insert(node_3rd);
                    real_connected_nodes[node].push_back(node_3rd);
                }
            }
        }
    }
    deque<pair<int, int>> que;
    unordered_set<int> accessed;
    que.push_back(make_pair(S, 0));
    int ans = -1;
    while (!que.empty()) {
        pair<int, int> info = que.front();
        int node = info.first;
        int count = info.second;
        // cout << node << endl;
        que.pop_front();
        if (node == T) {
            // cout << "target" << endl;
            ans = count;
            break;
        }
        accessed.insert(node);
        for (auto conn_node: real_connected_nodes[node]) {
            if (accessed.find(conn_node) == accessed.end()) {
                // cout << conn_node << "," << (count + 1) << endl;
                que.push_back(make_pair(conn_node, count + 1));
            }
        }
    }
    cout << ans << endl;

    return 0;
}
