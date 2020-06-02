#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

int main() {
    int l, r;
    int ans = 2018;
    cin >> l >> r;
    if ((l / 2019) < (r / 2019)) {
        ans = 0;
    } else {
        l %= 2019;
        r %= 2019;
        if (l >= r) {
            ans = 0;
        } else {
            for (int i = l; i < r; i++) {
                for (int j = i + 1; j <= r; j++) {
                    ans = min(ans, (i * j) % 2019);
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}