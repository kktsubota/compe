#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int h, w, m;
    cin >> h >> w >> m;
    vector<int> count_h(h, 0);
    vector<int> count_w(w, 0);

    set<pair<int, int>> points;
    for (int i = 0; i < m; i++) {
        int y, x;
        cin >> y >> x;
        y--; x--;
        points.insert(make_pair(y, x));
        count_h[y]++; count_w[x]++;
    }
    int ch_max = *max_element(count_h.begin(), count_h.end());
    int cw_max = *max_element(count_w.begin(), count_w.end());
    int ans = 0;
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            if (count_h[y] != ch_max || count_w[x] != cw_max) {
                continue;
            }
            if (points.find(make_pair(y, x)) != points.end()) {
                ans = max(ans, count_h[y] + count_w[x] - 1);
            } else {
                ans = max(ans, count_h[y] + count_w[x]);
            }
        }
    }
    cout << ans << endl;
    return 0;
}