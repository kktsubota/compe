#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
typedef long long int LL;
using namespace std;

int main(int argc, char const *argv[]) {
    int N, W;
    cin >> N >> W;
    vector<int> weight(N), value(N);
    vector<vector<LL>> sum_value(N + 1, vector<LL>(W + 1));
    for (int i = 0; i < N; i++) {
        cin >> weight[i] >> value[i];
    }
    for (int i = 0; i <= N; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0) {
                sum_value[i][w] = 0LL;
            } else {
                if (w >= weight[i - 1]) {
                    sum_value[i][w] = max(sum_value[i - 1][w], sum_value[i - 1][w - weight[i - 1]] + (LL) value[i - 1]);
                } else {
                    sum_value[i][w] = sum_value[i - 1][w];
                }
            }
        }
    }
    cout << sum_value[N][W] << endl;
    return 0;
}