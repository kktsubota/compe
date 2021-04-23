#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

template<typename T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;

int main() {
    ll n, m, x, y;
    cin >> n >> m >> x >> y;
    x--; y--;
    vector<vector<ll>> to(n);
    // accept duplicated edge
    // see https://twitter.com/fugu2929fat/status/1363811643247927297 for details.
    map<pair<ll, ll>, vector<pair<ll, ll>>> train;
    for (ll i = 0LL; i < m; i++) {
        ll a, b, t, k;
        cin >> a >> b >> t >> k;
        a--; b--;
        to[a].push_back(b);
        to[b].push_back(a);
        train[make_pair(a, b)].push_back(make_pair(t, k));
        train[make_pair(b, a)].push_back(make_pair(t, k));
    }

    vector<ll> visit_time(n, LONG_LONG_MAX);
    min_priority_queue<pair<ll, ll>> que;
    // time, point
    que.push(make_pair(0, x));
    while (!que.empty()) {
        auto p = que.top();
        que.pop();
        if (visit_time[p.second] != LONG_LONG_MAX) {
            continue;
        }
        visit_time[p.second] = p.first;
        if (p.second == y) {
            break;
        }

        for (ll node: to[p.second]) {
            for (auto k_t: train[make_pair(p.second, node)]) {
                // from p.second to node
                ll time_now = visit_time[p.second];
                // wait a train
                ll interval = k_t.second;
                ll time = k_t.first;
                if (time_now % interval != 0LL) {
                    time_now += (interval - time_now % interval);
                }
                // take a train
                time_now += time;
                que.push(make_pair(time_now, node));
            }
        }
    }
    if (visit_time[y] != LONG_LONG_MAX) {
        cout << visit_time[y] << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}