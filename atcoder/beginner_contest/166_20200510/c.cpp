#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> height(n);
    for (int i = 0; i < n; i++) {
        cin >> height[i];
    }

    vector<int> desk(n, 1);
    for (int j = 0; j < m; j++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        // cout << "(a, b): " << a << ", " << b << endl;
        if (height[a] > height[b]) {
            desk[b] = 0;
        } else if (height[a] < height[b]) {
            desk[a] = 0;
        } else {
            desk[a] = 0;
            desk[b] = 0;
        }
        // for(auto e: desk) {
        //     cout << e << ", ";
        // }
    }
    int ans = accumulate(desk.begin(), desk.end(), 0);
    cout << ans << endl;
    return 0;
}