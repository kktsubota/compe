#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main(int argc, char const *argv[])
{
    int N, M;
    cin >> N >> M;
    vector<vector<int>> edge(N);
    vector<vector<int>> edge_inv(N);
    vector<int> length(N);
    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        edge[x].push_back(y);
        edge_inv[y].push_back(x);
    }
    deque<int> children;
    int depth = 0;
    for (int i = 0; i < N; i++) {
        if (edge[i].size() == 0) {
            children.push_back(i);
        }
    }

    while (!children.empty()) {
        deque<int> parents;
        for (int child: children) {
            length[child] = depth;
            for (auto parent: edge_inv[child]) {
                parents.push_back(parent);
            }
        }
        depth++;
        children = parents;
    }
    cout << *max_element(length.begin(), length.end()) << endl;
    return 0;
}
