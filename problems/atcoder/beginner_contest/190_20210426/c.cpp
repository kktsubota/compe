#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<bool> to_vector(ll idx, ll vec_size) {
    vector<bool> vec(vec_size);
    for (int i = 0; i < vec_size; i++) {
        ll next_idx = idx >> 1;
        vec[i] = idx - (next_idx << 1);
        idx = next_idx;
    }
    return vec;
}

int main() {
    ll n, m;
    cin >> n >> m;
    vector<ll> A(m), B(m);
    for (int i = 0; i < m; i++) {
        cin >> A[i] >> B[i];
        A[i]--; B[i]--;
    }
    ll k;
    cin >> k;
    vector<ll> C(k), D(k);
    for (int i = 0; i < k; i++) {
        cin >> C[i] >> D[i];
        C[i]--; D[i]--;
    }

    ll ans = 0;
    for (ll choice = 0LL; choice < (2 << k); choice++) {
        vector<ll> plates(n, 0);
        vector<bool> vec = to_vector(choice, k);
        for (int i = 0; i < k; i++) {
            if (vec[i]) {
                // C
                plates[C[i]]++;
            } else {
                // D
                plates[D[i]]++;
            }
        }
        ll cnt = 0;
        for (int i = 0; i < m; i++) {
            if (plates[A[i]] != 0 && plates[B[i]] != 0) {
                cnt++;
            }
        }
        ans = max(ans, cnt);
    }
    cout << ans << endl;
    return 0;
}