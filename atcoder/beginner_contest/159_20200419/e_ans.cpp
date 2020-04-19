#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

bool geq_all(vector<int> v, int th) {
    for (auto e: v) {
        if (th < e) {
            return false;
        }
    }
    return true;
}

int main() {
    int h, w, k;
    cin >> h >> w >> k;
    vector<string> s;
    for (int i = 0; i < h; i++) {
        cin >> s[i];
    }
    // for (int i = 0; i < 1024; i++) {
    //     // {{0, 1}, {2}, {3}, ..., {9}}
    //     vector<int> split_point;
    //     vector<int> num_s(split_point.size(), 0);
    //     int start = 0;
    //     for (int j = 0; j < w; j++) {
    //         for (; start < split_point; start++) {
    //             for (int idx: split) {
    //                 num_s[idx] += (s[idx][j] - '0');
    //             }
    //         }
    //         geq_all()
    //     }
    // }
    return 0;
}