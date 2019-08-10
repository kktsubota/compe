#include <iostream>
#include <vector>

using namespace std;


int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<int> H(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> H[i];
    }

    bool ans = true;
    for (int i = n - 2; i >= 0 && ans; i--) {
        if (H[i] <= H[i + 1]) {
            continue;
        }
        H[i] -= 1;
        if (H[i] <= H[i + 1]) {
            continue;
        } else {
            ans = false;
        }
    }
    if (ans) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}
