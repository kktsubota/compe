#include <vector>
#include <iostream>
typedef long long int ll;

using namespace std;

int main(int argc, char const *argv[])
{
    int N;
    cin >> N;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    // values[i][j]: use A[i:j]
    vector<vector<ll>> values(N + 1, vector<ll>(N + 1));
    for (int offset = 0; offset <= N; offset++) {
        for (int i = 0; i <= (N - offset); i++) {
            if (offset == 0) {
                values[i][i + offset] = 0LL;
            } else if ((offset % 2 == 1 && N % 2 == 1) || (offset % 2 == 0 && N % 2 == 0)) {
                ll value = max(values[i][i+offset-1] + A[i+offset-1], values[i+1][i+offset] + A[i]);
                values[i][i + offset] = value;
            } else {
                ll value = min(values[i][i+offset-1] - A[i+offset-1], values[i+1][i+offset] - A[i]);
                values[i][i + offset] = value;
            }
        }
    }
    cout << values[0][N] << endl;
    return 0;
}
