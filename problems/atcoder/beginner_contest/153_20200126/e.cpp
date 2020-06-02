#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int H, N;
    cin >> H >> N;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
    }
    // int b_max = *max_element(B.begin(), B.end());
    vector<int> cost(H + 1, 0);
    cost[0] = 0;
    for (int h = 1; h <= H; h++) {
        int cost_min = 100000000;
        for (int i = 0; i < N; i++) {
            if (h < A[i]) {
                cost_min = min(cost_min, B[i]);
            } else {
                cost_min = min(cost_min, cost[h - A[i]] + B[i]);
            }
        }
        cost[h] = cost_min;
    }
    // cout << cost[H / 10] << endl;
    cout << cost[H] << endl;
    return 0;
}