#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    vector<int> B(A.size());
    copy(A.begin(), A.end(), B.begin());
    sort(B.begin(), B.end());
    vector<int> unique, count;
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            unique.push_back(B[i]);
            count.push_back(1);
            continue;
        }
        if (B[i] == B[i - 1]) {
            count[count.size() - 1] += 1;
        } else {
            unique.push_back(B[i]);
            count.push_back(1);
        }
    }
    unordered_map<int, int> num_count;
    unordered_map<int, int> count_num;
    ll base = 0LL;
    for (int i = 0; i < unique.size(); i++) {
        // cout << unique[i] << count[i] << endl;
        num_count[unique[i]] = count[i];
        count_num[count[i]] = unique[i];
        ll c = (ll) count[i];
        base += c * (c - 1) / 2;
    }
    for (int i = 0; i < n; i++) {
        ll c = (ll) num_count[A[i]];
        // cout << "A[i]: " << A[i] << "c: " << c << endl;
        ll ans = base;
        ans -= (c - 1);
        // ans -= c * (c - 1) / 2;
        // ans += (c - 1) * (c - 2) / 2;
        cout << ans << endl;
    }
    return 0;
}