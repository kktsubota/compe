#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

int main(int argc, char const *argv[]) {
    int N, K;
    cin >> N >> K;
    vector<int> Hs(N);
    for (int i = 0; i < N; i++) {
        cin >> Hs[i];
    }
    vector<long long int> costs(N, 0);
    for (int i = 0; i < N; i++) {
        if (i == 0) {
            continue;
        } 
        long long int cost;
        for (int k = 1; k <= K && k <= i; k++) {
            int diff = max(Hs[i] - Hs[i - k], Hs[i - k] - Hs[i]);
            if (k == 1) {
                cost = costs[i - k] + (long long int) diff;
            } else {
                cost = min(cost, costs[i - k] + (long long int) diff);
            }
        }
        costs[i] = cost;
    }
    cout << costs[N - 1] << endl;
    return 0;
}
