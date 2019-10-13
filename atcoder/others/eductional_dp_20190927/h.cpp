#include <vector>
#include <iostream>
#include <string>
typedef long long int ll;

using namespace std;

int main(int argc, char const *argv[]) {
    ll MOD = 1000000007LL;
    int H, W;
    cin >> H >> W;
    vector<string> grid(H);
    vector<vector<ll>> values(H, vector<ll>(W));
    for (int i = 0; i < H; i++) {
        cin >> grid[i];
    }
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (grid[i][j] == '#') {
                values[i][j] = 0LL;
                continue;
            }
            if (i == 0 && j == 0) {
                values[i][j] = 1LL;
            } else if (i == 0) {
                values[i][j] = values[i][j - 1];
            } else if (j == 0) {
                values[i][j] = values[i - 1][j];
            } else {
                values[i][j] = values[i - 1][j] + values[i][j - 1];
                values[i][j] = values[i][j] % MOD;
            }
            // cout << i << j << values[i][j] << endl;
        }
    }
    cout << values[H - 1][W - 1] << endl;
    return 0;
}
