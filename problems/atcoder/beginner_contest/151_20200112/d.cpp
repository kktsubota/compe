#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <map>
#include <utility>
#include <algorithm>

using namespace std;


int calc_max_dist(vector<string> S, vector<pair<int, int>> points, pair<int, int> p_s) {
    int h = S.size();
    int w = S[0].size();
    map<pair<int, int>, int> distance;
    for (auto p: points) {
        distance[p] = -1;
    }
    queue<pair<pair<int, int>, int>> que;
    que.push(make_pair(p_s, 0));
    while (!que.empty()) {
        auto t = que.front();
        auto p = t.first;
        auto d = t.second;
        que.pop();
        auto y = p.first; auto x = p.second;
        if (0 > x || x >=  w || y < 0 || y >= h) {
            continue;
        }
        if (S[y][x] == '#') {
            continue;
        }
        if (distance[p] != -1) {
            continue;
        }

        distance[p] = d;
        que.push(make_pair(make_pair(y, x - 1), d + 1));
        que.push(make_pair(make_pair(y, x + 1), d + 1));
        que.push(make_pair(make_pair(y - 1, x), d + 1));
        que.push(make_pair(make_pair(y + 1, x), d + 1));
    }
   
    int max_dist = -1;
    for (auto d: distance) {
        max_dist = max(max_dist, d.second);
    }
    return max_dist;
}

int main(int argc, char const *argv[])
{
    int h, w;
    cin >> h >> w;

    vector<string> S(h);
    for (int y = 0; y < h; y++) {
        cin >> S[y];
    }

    vector<pair<int, int>> points;
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            if (S[y][x] == '.') {
                points.push_back(make_pair(y, x));
            }
        }
    }
    vector<int> distance;
    for (int i = 0; i < points.size(); i++) {
        auto p_s = points[i];
        int d = calc_max_dist(S, points, p_s);
        distance.push_back(d);
    }
    cout << *max_element(distance.begin(), distance.end()) << endl;
    return 0;
}
