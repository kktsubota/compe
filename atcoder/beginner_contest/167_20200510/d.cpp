#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n, k;
    cin >> n >> k;
    vector<ll> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        A[i]--;
    }
    set<ll> path_set;
    vector<ll> path_vec(n + 1, -1);
    ll point = 0LL;
    path_set.insert(point);

    ll idx = 0LL;
    path_vec[idx] = point;

    ll ans;
    while (true) {
        point = A[point];
        // cout << "point: " << point << endl;
        if (path_set.find(point) == path_set.end()) {
            point = point;
            path_set.insert(point);
            idx++;
            path_vec[idx] = point;
        } 
        // detect loop
        else {
            auto vec_iter = std::find(path_vec.begin(), path_vec.end(), point);
            // for (auto p: path_vec) {
            //     cout << p;
            // }
            ll offset = distance(path_vec.begin(), vec_iter);
            ll length = path_set.size() - offset;

            // cout << "offset: " << offset << ", length: " << length << endl;
            if (k < offset) {
                ans = path_vec[k];
            } else {
                ans = path_vec[(k - offset) % length + offset];
            }
            break;
        }        
    }
    cout << (ans + 1LL) << endl;
    return 0;
}