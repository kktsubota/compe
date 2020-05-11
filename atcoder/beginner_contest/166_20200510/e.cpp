#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    int n;
    cin >> n;
    vector<int> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        a[i] = h[i] + i;
        b[i] = h[i] - i;
    }
    unordered_map<int, vector<int>> indices;
    for (int i = 0; i < n; i++) {
        indices[b[i]].push_back(i);
    }

    ll ans = 0LL;
    // a[i] + b[j] = 0 (j > i)
    for (int i = 0; i < n; i++) {
        // index j where b[j] = -a[i]
        vector<int> index = indices[-a[i]];
        auto pointer = upper_bound(index.begin(), index.end(), i);
        ll d = (ll) distance(pointer, index.end());
        ans += d;
    }
    cout << ans << endl;
    return 0;
}