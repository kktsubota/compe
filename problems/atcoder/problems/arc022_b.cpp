#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        A[i]--;
    }
    // head is included
    int head = 0;
    int ans = 0;
    vector<int> indices(100001, -1);
    for (int i = 0; i < n; i++) {
        // appeared in indices[A[i]]
        if (indices[A[i]] >= head) {
            // i is not included
            ans = max(ans, i - indices[A[i]]);
            head = indices[A[i]] + 1;
            indices[A[i]] = i;
        } else {
            // i is included
            ans = max(ans, i - head + 1);
            indices[A[i]] = i;
        }

        // cout << "head: " << head << " [";
        // for (auto idx: indices) {
        //     cout << idx << ", ";
        // }
        // cout << "] ans: " << ans << endl;
    }
    cout << ans << endl;
    return 0;
}