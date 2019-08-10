#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    int H, W;
    cin >> H >> W;
    vector<string> mass(H);
    for (int i = 0; i < H; i++) {
        string s;
        cin >> s;
        mass[i] = s;
    }
    vector<vector<int*>> count_row(H, vector<int*>(W));
    vector<vector<int*>> count_col(H, vector<int*>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            count_row[i][j] = new int;
            count_col[i][j] = new int;
        }
    }
    int* zero = new int;
    *zero = 0;
    int* count;
    for (int i = 0; i < H; i++) {
        count = new int;
        *count = 0;
        for (int j = 0; j < W; j++) {
            // cout << "(" << i << ", " << j << ")" << endl;
            if (mass[i][j] == '#') {
                count_row[i][j] = zero;
                count = new int;
                // values_row.push_back(count);
                *count = 0;
            } else {
                *count += 1;
                count_row[i][j] = count;
            }
        }
    }
    // for (auto c_row: count_row) {
    //     for (auto c: c_row) {
    //         cout << *c << " ";
    //     }
    //     cout << endl;
    // }
    for (int j = 0; j < W; j++) {
        count = new int;
        *count = 0;
        // values_col.push_back(count);
        for (int i = 0; i < H; i++) {
            // cout << "(" << i << ", " << j << ")" << endl;
            if (mass[i][j] == '#') {
                count_col[i][j] = zero;
                count = new int;
                // values_col.push_back(count);
                *count = 0;
            } else {
                *count += 1;
                count_col[i][j] = count;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            ans = max(ans, *count_row[i][j] + *count_col[i][j] - 1);
        }
    }
    cout << ans << endl;
    return 0;
}
