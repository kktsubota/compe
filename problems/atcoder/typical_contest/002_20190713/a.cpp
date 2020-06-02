#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <queue>
#include <set>

using namespace std;

int main(int argc, char const *argv[]) {
    int R, C;
    cin >> R >> C;
    int sy, sx, gy, gx, ans;
    cin >> sy >> sx;
    cin >> gy >> gx;
    sy--; sx--; gy--; gx--;
    vector<string> stage(R);
    for (int i = 0; i < R; i++) {
        cin >> stage[i];
    }
    queue<pair<pair<int, int>, int>> Q;
    set<pair<int, int>> visited;
    Q.push(make_pair(make_pair(sy, sx), 0));
    while (!Q.empty()) {
        auto q = Q.front();
        Q.pop();
        pair<int, int> point = q.first;
        // cout << point.first << ", " << point.second << endl;
        int depth = q.second;
        if (point.first < 0 || point.first >= R) {
            continue;
        } else if (point.second < 0 || point.second >= C) {
            continue;
        } else {
            if (stage[point.first][point.second] == '#') {
                continue;
            }
        }
        if (visited.find(point) != visited.end()) {
            continue;
        }
        visited.insert(point);

        if (point.first == gy && point.second == gx) {
            ans = depth;
            break;
        }
        pair<int, int> p_up = make_pair(point.first - 1, point.second);
        pair<int, int> p_down = make_pair(point.first + 1, point.second);
        pair<int, int> p_left = make_pair(point.first, point.second - 1);
        pair<int, int> p_right = make_pair(point.first, point.second + 1);
        Q.push(make_pair(p_up, depth + 1));
        Q.push(make_pair(p_down, depth + 1));
        Q.push(make_pair(p_left, depth + 1));
        Q.push(make_pair(p_right, depth + 1));
    }
    cout << ans << endl;
    return 0;
}
