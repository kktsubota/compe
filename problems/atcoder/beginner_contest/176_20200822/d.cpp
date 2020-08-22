#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int pair_to_int(pair<int, int> pair) {
    return pair.first * 10000 + pair.second;
}
pair<int, int> int_to_pair(int i) {
    int f = i / 10000;
    return make_pair(f, i - f * 10000);
}

int calc_cost(pair<int, int> a, pair<int, int> b) {
    int i = a.first - b.first;
    int j = a.second - b.second;
    int c;
    if (min(abs(i), abs(j)) == 0 && max(abs(i), abs(j)) == 1) {
        c = 0;
    } else {
        c = 1;
    }
    return c;
}

int main() {
    int h, w;
    cin >> h >> w;
    pair<int, int> start, dest;
    cin >> start.first >> start.second;
    start.first--; start.second--;
    cin >> dest.first >> dest.second;
    dest.first--; dest.second--;

    vector<string> mass(h);
    for (int i = 0; i < h; i++) {
        cin >> mass[i];
    }
    unordered_map<int, vector<int>> to;
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            auto a = make_pair(y, x);
            if (mass[a.first][a.second] == '#') {
                continue;
            }
            for (int i = -2; i <= 2; i++) {
                for (int j = -2; j <= 2; j++) {
                    if (i == 0 && j == 0) {
                        continue;
                    }
                    auto b = make_pair(y + i, x + j);
                    if (b.first < 0 || b.first >= h) {
                        continue;
                    }
                    if (b.second < 0 || b.second >= w) {
                        continue;
                    }
                    if (mass[b.first][b.second] == '#') {
                        continue;
                    }
                    to[pair_to_int(a)].push_back(pair_to_int(b));
                    to[pair_to_int(b)].push_back(pair_to_int(a));
                    // cout << "(" << a.first << "," << a.second << ")" << "(" << b.first << "," << b.second << ")" << cost[make_pair(a, b)] << endl;
                }
            }
        }
    }
    // dijkstra
    int NEG_DIST_MAX = -10010010;
    unordered_map<int, int> neg_dist;
    unordered_map<int, bool> visited;

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            neg_dist[y * 10000 + x] = NEG_DIST_MAX;
            visited[y * 10000 + x] = false;
        }
    }
    neg_dist[pair_to_int(start)] = 0;

    // neg_dist, point
    priority_queue<pair<int, int>> que;
    que.push(make_pair(neg_dist[pair_to_int(start)], pair_to_int(start)));

    while (!que.empty()) {
        // pop maximum neg dist
        auto q = que.top();
        que.pop();
        auto u = q.second;
        if (visited[u]) {
            continue;
        }
        visited[u] = true;

        // cout << q.first << "(" << u.first << "," << u.second << ")" << mass[u.first][u.second] << endl;
        for (auto v: to[u]) {
            int nd = neg_dist[u] - calc_cost(int_to_pair(u), int_to_pair(v));
            if (neg_dist[v] < nd) {
                neg_dist[v] = nd;
                que.push(make_pair(nd, v));
            }
        }
    }
    if (neg_dist[pair_to_int(dest)] <= NEG_DIST_MAX) {
        cout << "-1" << endl;
    } else {
        cout << - neg_dist[pair_to_int(dest)] << endl;
    }

    return 0;
}