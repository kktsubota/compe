#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n;
    cin >> n;
    ll c = (ll) sqrt((double) n) + 1LL;
    set<ll> complement_set;
    for (ll a = 2LL; a <= c; ++a) {
        ll m = a;
        for (ll b = 2LL;;b++) {
            m *= a;
            if (m > n) {
                break;
            }
            complement_set.insert(m);
        }
    }
    cout << n - complement_set.size() << endl;
    return 0;
}