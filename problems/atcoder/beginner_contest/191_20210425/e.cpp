#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


ll calc_cost(vector<vector<ll>> &to, map<pair<ll, ll>, ll> &cost, ll src, ll dest) {
    priority_queue<pair<ll, ll>> que;
    vector<bool> visited(to.size(), false);
    // cost, point
    que.push({- 0, src});
    while (!que.empty()) {
        auto p = que.top();
        que.pop();
        if (visited[p.second]) {
            continue;
        }
        if (p.second == dest) {
            return - p.first;
        }
        visited[p.second] = true;
        for (ll node: to[p.second]) {
            // from p.second to node
            ll c = - p.first + cost[{p.second, node}];
            que.push({- c, node});
        }
    }
    return -1;
}

int main() {
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> to(n);
    map<pair<ll, ll>, ll> cost;
    vector<ll> ans(n, LONG_LONG_MAX);
    for (ll i = 0; i < m; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--; b--;

        if (a == b) {
            // fix by watching test case
            ans[a] = min(ans[a], c);
            continue;
        }

        if (cost.find({a, b}) != cost.end()) {
            cost[{a, b}] = min(cost[{a, b}], c);
        } else {
            cost[{a, b}] = c;
        }
        to[a].push_back(b);
    }
    for (ll city = 0; city < n; city++) {
        vector<ll> c_dests = {ans[city]};
        for (ll dest: to[city]) {
            ll c_dest = calc_cost(to, cost, dest, city);
            if (c_dest == -1) {
                c_dests.push_back(LONG_LONG_MAX);
            } else {
                c_dests.push_back(cost[{city, dest}] + c_dest);
            }
        }
        ans[city] = *min_element(c_dests.begin(), c_dests.end());
    }
    for (auto a: ans) {
        if (a == LONG_LONG_MAX) {
            a = -1;
        }
        cout << a << endl;
    }
    return 0;
}