#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <iomanip>

using namespace std;

int main(int argc, char const *argv[]) {
    int N;
    cin >> N;
    vector<long double> prob(N);
    for (int i = 0; i < N; i++) {
        cin >> prob[i];
    }
    vector<vector<long double>> values(N + 1, vector<long double>(N + 1));
    // use coin 1 - i
    for (int i = 1; i <= N; i++) {
        // num of front
        for (int j = 0; j <= i; j++) {
            if (i == 1 && j == 1) {
                values[i][j] = prob[i-1];
            } else if (i == 1 && j == 0) {
                values[i][j] = 1.0L - prob[i-1];
            } else if (j == 0) {
              values[i][j] = (1.0L - prob[i-1]) * values[i-1][j];
            } else if (j > i) {
                values[i][j] = 0.0L;
            } else {
                values[i][j] = prob[i-1] * values[i-1][j-1] + (1.0L - prob[i-1]) * values[i-1][j];
            }
        }
    }
    // for (int i = 1; i <= N; i++) {
    //     cout << i << ": ";
    //     for (auto v: values[i]) {
    //         cout << v << ", ";
    //     }
    //     cout << endl;
    // }

    // 0, 1, 2, 3 => 2, 3
    // 0, 1, 2 => 2
    cout << setprecision(10) << accumulate(values[N].begin() + (N/2 + 1), values[N].end(), 0.0L) << endl;
    return 0;
}
