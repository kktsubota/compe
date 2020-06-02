#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    int N, T;
    cin >> N >> T;
    vector<int> A(N);
    vector<int> B(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
    }
    cout << "read" << endl;
    // i, t
    int dp[301][301];
    // unordered_set<int> index[3001][6001];
    cout << "prepare" << endl;

    return 0;
}