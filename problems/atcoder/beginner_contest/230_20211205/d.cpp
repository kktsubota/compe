#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


vector<int> argsort(vector<int>& vec) {
    vector<pair<int, int>> vec_pair(vec.size());
    for (int i = 0; i < vec.size(); i++) {
        vec_pair[i] = make_pair(vec[i], i);
    }
    sort(vec_pair.begin(), vec_pair.end());
    vector<int> indices(vec_pair.size());
    for (int i = 0; i < vec_pair.size(); i++) {
        indices[i] = vec_pair[i].second;
    }
    return indices;
}

int main() {
    int n, d;
    cin >> n >> d;
    vector<int> wall_left(n);
    vector<int> wall_right(n);
    for (int i = 0; i < n; ++i) {
        cin >> wall_left[i] >> wall_right[i];
    }
    vector<int> index_l = argsort(wall_left);
    vector<int> index_r = argsort(wall_right);
    sort(wall_left.begin(), wall_left.end());
    sort(wall_right.begin(), wall_right.end());
    vector<bool> exist_flag(n, true);

    int ans = 0;
    // i_l: index for left
    int i_l_beg = 0;
    // i_r: index for right
    for (int i_r = 0; i_r < n; ++i_r) {
        // 1. break the most left wall
        int idx_break_left = index_r[i_r];
        // already broken
        if (!exist_flag[idx_break_left]) {
            continue;
        }
        // below line is not required.
        exist_flag[idx_break_left] = false;

        // punch [wall, wall + d)
        // 2. break other walls whose left is smaller than wall + d
        // if the left is smaller than wall, it should be [smaller than wall. larger than wall)
        int wall = wall_right[i_r];

        auto it = lower_bound(wall_left.begin() + i_l_beg, wall_left.end(), wall + d);
        int i_l_end = std::distance(wall_left.begin(), it);
        // index_break
        for (int j = i_l_beg; j < i_l_end; j++) {
            auto idx = index_l[j];
            exist_flag[idx] = false;
        }
        i_l_beg = i_l_end;
        ans++;
    }

    cout << ans << endl;
    return 0;
}