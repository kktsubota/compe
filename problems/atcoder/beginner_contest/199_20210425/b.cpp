#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    vector<int> A(n), B(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> B[i];
    }
    int ans = 0;
    for (int x = 1; x <= 1000; x++) {
        bool skip_flag = false;
        for (int i = 0; i < n; i++) {
            if (A[i] > x || x > B[i]) {
                skip_flag = true;
                break;
            }
        }
        if (!skip_flag) {
            ans += 1;
        }        
    }
    cout << ans << endl;
    return 0;
}