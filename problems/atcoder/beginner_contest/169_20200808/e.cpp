#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    if (n % 2 == 1) {
        int mid_min = a[n / 2];
        int mid_max = b[n / 2];
        cout << mid_max - mid_min + 1 << endl;
    } else {
        int left_min = a[n / 2 - 1];
        int left_max = b[n / 2 - 1];;
        int right_min = a[n / 2];
        int right_max = b[n / 2];
        // a left sample is from [left_min, left_max]
        // a right sample is from [right_min, right_max]
        int mid_min_twice = left_min + right_min;
        int mid_max_twice = left_max + right_max;
        cout << mid_max_twice - mid_min_twice + 1 << endl;
    }
    return 0;
}