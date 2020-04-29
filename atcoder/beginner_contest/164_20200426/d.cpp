#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    string s;
    cin >> s;
    vector<ll> count(2019, 0);
    ll ans = 0LL;
    // deque<pair<int, int>> ans;

    for (int i = 0; i < s.length(); i++) {
        int n = s[i] - '0';
        vector<ll> count_new(2019, 0);
        for (int j = 0; j < 2019; j++) {
            count_new[(10 * j + n) % 2019] = count[j];
        }
        count_new[n] += 1LL;
        count = count_new;
        // for (int j = 0; j < 2019; j++) {
        //     if (count[j] != 0) {
        //         cout << j << ", ";
        //     }
        // }
        // cout << endl;
        ans += count[0];
    }
    cout << ans << endl;
    return 0;
}