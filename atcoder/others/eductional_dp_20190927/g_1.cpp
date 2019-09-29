#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

int main(int argc, char const *argv[])
{
    int N, M;
    cin >> N >> M;
    vector<set<int>> edge(N);
    vector<set<int>> edge_inv(N);
    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        edge[x].insert(y);
        edge_inv[y].insert(x);
    }
    // topological sort
    vector<int> numbers(N);
    queue<int> children;
    int num = 0;
    for (int i = 0; i < N; i++) {
        if (edge[i].size() == 0) {
            children.push(i);
        }
    }
    while (!children.empty()) {
        int child = children.front();
        children.pop();
        numbers[child] = N - num;
        num++;
        for (auto parent: edge_inv[child]) {
            edge[parent].erase(child);
            if (edge[parent].size() == 0) {
                children.push(parent);
            }
        }
    }
    // fill from the node whose number is small.
    vector<pair<int, int>> nodes;
    vector<int> length(N);
    for (int i = 0; i < N; i++) {
        nodes.emplace_back(make_pair(numbers[i], i));
    }
    sort(nodes.begin(), nodes.end());
    for (auto node: nodes) {
        // priority, No. of nodes
        // cout << node.first << node.second << endl;
        if (edge_inv[node.second].empty()) {
            length[node.second] = 0;
        } else {
            length[node.second] = -1;
            for (auto nd: edge_inv[node.second]) {
                length[node.second] = max(length[node.second], length[nd] + 1);
            }
        }
    }
    // for (int i = 0; i < N; i++) {
    //     cout << i + 1 << " number: " << numbers[i] << ", length: " << length[i] << endl;
    // }
    cout << *max_element(length.begin(), length.end()) << endl;
    return 0;
}
