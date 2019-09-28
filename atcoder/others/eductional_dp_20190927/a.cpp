#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

int main(int argc, char const *argv[]) {
    int N;
    cin >> N;
    vector<int> Hs(N);
    for (int i = 0; i < N; i++) {
        cin >> Hs[i];
    }
    vector<long long int> costs(N, 0);
    for (int i = 0; i < N; i++) {
        if (i == 0) {
            continue;
        } else if (i == 1) {
            int diff_1 = max(Hs[i] - Hs[i - 1], Hs[i - 1] - Hs[i]);
            costs[1] = (long long int) diff_1;
        } else {
            int diff_1 = max(Hs[i] - Hs[i - 1], Hs[i - 1] - Hs[i]);
            int diff_2 = max(Hs[i] - Hs[i - 2], Hs[i - 2] - Hs[i]);
            costs[i] = min(diff_1 + costs[i - 1], diff_2 + costs[i - 2]);
        }
    }
    cout << costs[N - 1] << endl;
    return 0;
}
