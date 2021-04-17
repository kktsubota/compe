#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll pow_ll(const ll x, const ll a) {
    if (a == 0LL) {
        return 1LL;
    } else {
        ll half = pow(x, a / 2);
        if (a % 2 == 0) {
            return half * half;
        } else {
            return half * half * x;
        }
    }
}


ll or_element(vector<ll>::const_iterator first, vector<ll>::const_iterator last) {
    ll value = 0LL;
    for (auto iter = first; iter != last; ++iter) {
        value = value | *iter;
    }
    return value;
}

ll calculate(vector<ll> a, vector<ll> bin) {
    vector<int> starts;
    vector<int> ends;
    starts.push_back(0);
    for (int i = 0; i < bin.size(); i++) {
        if (bin[i] == 1) {
            ends.push_back(i + 1);
            starts.push_back(i + 1);
        }
    }
    ends.push_back(a.size());

    ll value = 0LL;
    for (int i = 0; i < starts.size(); i++) {
        value = value ^ or_element(a.begin() + starts[i], a.begin() + ends[i]);
    }
    return value;
}
int main() {
    int n;
    cin >> n;
    vector<ll> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    ll n_interval = (ll) A.size() - 1LL;
    ll ans = 300010001000LL;
    for (ll i = 0LL; i < pow_ll(2LL, n_interval); i++) {
        ll value = i;
        vector<ll> bin(n_interval);
        for (ll j = 1LL; j <= n_interval; j++) {
            ll flag = value >> (n_interval - j);
            value -= (flag << (n_interval - j));            
            bin[j - 1] = flag;
        }
        ll a = calculate(A, bin);
        ans = min(ans, a);
    }
    cout << ans << endl;    
    return 0;
}