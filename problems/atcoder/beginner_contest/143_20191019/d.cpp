#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int main(int argc, char const *argv[]) {
    int N;
    cin >> N;
    vector<int> L(N);
    for (int i = 0; i < N; i++) {
        cin >> L[i];
    }
    sort(L.begin(), L.end());

    long long int ans = 0LL;
    // a <= b <= c
    for (int i = 0; i < (N - 2); i++) {
        for (int j = (i + 1); j < (N - 1); j++) {
            int a = L[i];
            int b = L[j];
            // b < c < a + b
            int ans_ = 0;

            // includes L[N - 1] == b
            if (L[N - 1] < (a + b)) {
                ans_ = ((N - 1) - j);
            } else {
                // b < c < a + b
                // c >= a + b
                auto it = lower_bound(L.begin(), L.end(), a + b);
                // cout << (it - L.begin()) << endl;
                ans_ = ((it - L.begin()) - j - 1);
            }
            // cout << "(a, b, Lmax) = " << a << ", " << b << ", " << L[N - 1] << endl;
            // cout << ans_ << endl;
            ans += (long long int) ans_;
        }
    }
    cout << ans << endl;
    return 0;
}
