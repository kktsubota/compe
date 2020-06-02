#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> to(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        to[a].push_back(b);
        to[b].push_back(a);
    }
    vector<int> prev(n);
    vector<int> dist(n);
    queue<int> que;

    // BPS
    int MAX_DIST = 10000000;
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            dist[i] = 0;
        } else {
            dist[i] = MAX_DIST;
        }
    }
    que.push(0);

    unordered_set<int> not_visited;
    for (int i = 0; i < n; i++) {
        not_visited.insert(i);
    }

    while (!que.empty()) {
        int u = que.front();
        que.pop();

        // visited
        if (not_visited.find(u) == not_visited.end()) {
            continue;
        }
        for (int v: to[u]) {
            int d = dist[u] + 1;
            if (dist[v] > d) {
                dist[v] = d;
                prev[v] = u;
                que.push(v);
            }
        }
        not_visited.erase(u);
        if (not_visited.size() == 0) {
            break;
        }
    }

    // for (int i = 0; i < n; i++) {
    //     if (dist[i] >= MAX_DIST) {
    //         cout << "No" << endl;
    //         return 0;
    //     }
    // }
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            cout << "Yes" << endl;
        } else {
            cout << (prev[i] + 1) << endl;
        }
    }
    return 0;
}