#include <vector>
#include <algorithm>
#include <iostream>

typedef long long int ll;
using namespace std;


int main(int argc, char const *argv[])
{
    ll MOD = 1000000007LL;
    ll n, k;
    cin >> n >> k;
    vector<ll> A(n);
    for (ll i = 0LL; i < n; i++) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    ll ans = 0LL;

    vector<ll> combinations;
    for (ll j = 0LL;; j++) {
        ll i = k - 1 + j;
        if (i >= n) {
            break;
        }

        if (j == 0LL) {
            combinations.push_back(1LL);
        } else {
            combinations.push_back(combinations[j - 1] * i / (i - k + 1));
        }
    }
    reverse(combinations.begin(), combinations.end());

    // for (auto a: A) {
    //     cout << a << ", ";
    // }
    // cout << endl;
    // for (auto c: combinations) {
    //     cout << c << ", ";
    // }
    // cout << endl;

    for (ll j = 0LL;; j++) {
        ll i = k - 1 + j;
        if (i >= n) {
            break;
        }
        ans += (A[A.size() - j - 1] * combinations[j]);
        ans = ans % MOD;
        ans -= (A[j] * combinations[j]);
        if (ans < 0LL) {
            ans = ans + (- ans / MOD + 1) * MOD;
        }
        ans = ans % MOD;
    }
    cout << ans << endl;
    return 0;
}
