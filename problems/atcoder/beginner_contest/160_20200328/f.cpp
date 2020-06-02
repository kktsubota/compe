#include <bits/stdc++.h>
typedef long long int ll;

using namespace std;

vector<map<int, ll>> memo(201001);
ll MOD = 1000000007LL;

ll get_ans(int node, int parent, vector<vector<int>> &edges) {
    // parent: from parent
    ll ans = 1LL;
    if (memo[parent].find(node) != memo[parent].end()) {
        return memo[parent][node];
    }
    int n_childs = 0;
    for (int child: edges[node]) {
        if (child == parent) {
            continue;
        }
        ans *= get_ans(child, node, edges);
        ans %= MOD;
        n_childs += 1;
    }
    if (n_childs != 0) {
        ans *= n_childs;
        ans %= MOD;
    }
    memo[parent][node] = ans;
    // if n_childs == 0; ans == 1LL
    return ans;
}

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    vector<vector<int>> edges(n);
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    for (int k = 0; k < n; k++) {
        ll ans = 1LL;
        for (int node: edges[k]) {
            ans *= get_ans(node, k, edges);
            ans %= MOD;
        }
        ans *= edges[k].size();
        ans %= MOD;
        cout << ans << endl;
    }
    return 0;
}
