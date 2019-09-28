#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
#include <numeric>

typedef long long int LL;
using namespace std;

int main(int argc, char const *argv[]) {
    int N, W;
    cin >> N >> W;
    vector<int> weight(N), value(N);
    for (int i = 0; i < N; i++) {
        cin >> weight[i] >> value[i];
    }
    int V = accumulate(value.begin(), value.end(), 0);
    LL WINF = (LL) (W + 1);
    vector<vector<LL>> sum_weight(N + 1, vector<LL>(V + 1));

    for (int i = 0; i <= N; i++) {
        for (int v = 0; v <= V; v++) {
            if (v == 0) {
                sum_weight[i][v] = 0LL;
                continue;
            }
            if (i == 0) {
                sum_weight[i][v] = WINF;
            }
            else {
                if (v - value[i - 1] >= 0) {
                    sum_weight[i][v] = min(sum_weight[i - 1][v], sum_weight[i - 1][v - value[i - 1]] + (LL) weight[i - 1]);
                } else {
                    sum_weight[i][v] = sum_weight[i - 1][v];
                }
            }
        }
    }
    // cout << sum_weight[N][V] << endl;
    int ans;
    for (int v = V; v >= 0; v--) {
        if (sum_weight[N][v] <= W) {
            ans = v;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}