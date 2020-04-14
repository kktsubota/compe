#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;

ll gcd(ll a, ll b) {
    if (a < b) {
        return gcd(b, a);
    }
    ll r = a % b;
    if (r == 0) {
        return b;
    } else {
        return gcd(b, r);
    }
}

int main(int argc, char const *argv[]) {
    ll K;
    cin >> K;
    ll ans = 0LL;
    for (ll a = 1LL; a <= K; a++) {
        for (ll b = 1LL; b <= K; b++) {
            for (ll c = 1LL; c <= K; c++) {
                ll g = gcd(gcd(a, b), c);
                ans += g;
            }
        }
    }
    cout << ans << endl;
    return 0;
}