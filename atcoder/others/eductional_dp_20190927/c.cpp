#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

int main(int argc, char const *argv[]) {
    int N;
    cin >> N;
    vector<vector<int>> happiness(N, vector<int>(3));
    for (int i = 0; i < N; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (i == 0) {
            happiness[i][0] = a;
            happiness[i][1] = b;
            happiness[i][2] = c;
        } else {
            happiness[i][0] = max(happiness[i - 1][1], happiness[i - 1][2]) + a;
            happiness[i][1] = max(happiness[i - 1][2], happiness[i - 1][0]) + b;
            happiness[i][2] = max(happiness[i - 1][0], happiness[i - 1][1]) + c;
        }
    }
    cout << *max_element(happiness[N - 1].begin(), happiness[N - 1].end()) << endl;
    return 0;
}