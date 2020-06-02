#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<int> As(n + 1);
    vector<int> Bs(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> As[i];
    }
    vector<unordered_set<int>> divisor(n + 1);
    // n*sqrt(n)
    for (int i = 1; i <= n; i++) {
        for (int div = 1; div*div <= i; div++) {
            if (i % div == 0) {
                divisor[i].insert(div);
                divisor[i].insert(i / div);
            }
        }
    }
    // for (int i = 1; i <= n; i++) {
    //     cout << i << ": ";
    //     for (auto div: divisor[i]) {
    //         cout << div << ", ";
    //     }
    //     cout << endl;
    // }

    int k = n;
    // log(n) * n/2 * 2sqrt(n)
    while (k != 0) {
        // cout << "k " << k << endl;
        for (int i = (k / 2 + 1); i <= k; i++) {
            Bs[i] = As[i];

            // sqrt(n)
            for (auto div: divisor[i]) {
                As[div] = As[div] ^ Bs[i];
            }
        }
        k = k / 2;
    }

    // cout << "B:";
    // for (int i = 1; i <= n; i++) {
    //     cout << Bs[i] << ", ";
    // }
    // cout << endl;
    int m = accumulate(Bs.begin() + 1, Bs.end(), 0);
    cout << m << endl;
    if (m != 0) {
        string s;
        for (int i = 1; i <= n; i++) {
            if (Bs[i] == 1) {
                cout << i;
                m--;
                if (m == 0) {
                    cout << endl;
                    break;
                } else {
                    cout << " ";
                }
            }
        }
    }
    return 0;
}
