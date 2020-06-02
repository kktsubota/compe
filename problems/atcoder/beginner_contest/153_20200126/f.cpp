#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int main() {
    int n, d, a;
    cin >> n >> d >> a;
    vector<int> x(n), h(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> h[i];
    }

    vector<int> indices(n);
    iota(indices.begin(), indices.end(), 0);
    sort(indices.begin(), indices.end(), [&x](size_t i1, size_t i2) {
        return x[i1] < x[i2];
    });

    // greedy
    long long int ans = 0LL;
    for (int i = 0; i < n; i++) {
        int index = indices[i];
        if (h[index] <= 0) {
            continue;
        }
        int num = (h[index] + a - 1) / a;
        ans += (long long int) num;
        for (int j = i + 1; j < n; j++) {
            // cout << x[index] << d << x[indices[j]] << endl;
            if (x[index] + 2 * d < x[indices[j]]) {
                break;
            }
            if (h[indices[j]] > 0) {
                h[indices[j]] -= a * num;
            }
        }
        // cout << ans << endl;
    }
    cout << ans << endl;
    return 0;
}