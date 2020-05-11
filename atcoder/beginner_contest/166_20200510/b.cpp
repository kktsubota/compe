#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> n_candies(n, 0);
    for (int i = 0; i < k; i++) {
        int d;
        cin >> d;
        for (int j = 0; j < d; j++) {
            int a;
            cin >> a;
            a--;
            n_candies[a]++;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (n_candies[i] == 0) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}