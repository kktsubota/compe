#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    int n;
    cin >> n;
    vector<int> colors(n);
    for (int i = 0; i < n; i++) {
        cin >> colors[i];
    }
    vector<vector<int>> edges(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    vector<int> answer;
    vector<bool> is_accessed(n, false);
    vector<set<int>> color_set(n);
    queue<int> que;
    
    // initialize
    que.push(0);
    answer.push_back(0);

    while (!que.empty()) {
        int node = que.front();
        que.pop();
        if (is_accessed[node]) {
            continue;
        }
        int color = colors[node];
        is_accessed[node] = true;
        // O(n) operation
        auto next_color_set = color_set[node];
        // O(log n) operation
        next_color_set.insert(color);

        for (int to: edges[node]) {
            if (is_accessed[to]) {
                continue;
            }
            color_set[to] = next_color_set;
            // color_set[to] does not cotain colors[to]
            if (color_set[to].find(colors[to]) == color_set[to].end()) {
                answer.push_back(to);
            }
            que.push(to);
        }
    }
    // O(n log n) operation
    sort(answer.begin(), answer.end());
    for (auto ans: answer) {
        cout << (ans + 1) << endl;
    }
    return 0;
}