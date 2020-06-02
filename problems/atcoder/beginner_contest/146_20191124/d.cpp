#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <utility>
#include <map>
#include <set>

using namespace std;


int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    vector<vector<int>> to(n);
    map<pair<int, int>, int> color;
    vector<pair<int, int>> order;
    for (int i = 0; i < (n - 1); i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        to[a].push_back(b);
        to[b].push_back(a);
        color[make_pair(a, b)] = 0;
        color[make_pair(b, a)] = 0;
        order.push_back(make_pair(a, b));
    }
    int c_max = 0;
    for (int i = 0; i < n; i++) {
        set<int> used;
        for (int j = 0; j < to[i].size(); j++) {
            int c = color[make_pair(i, to[i][j])];
            if (c != 0) {
                used.insert(c);
            }
        }
        for (int j = 0; j < to[i].size(); j++) {
            int c = color[make_pair(i, to[i][j])];
            if (c != 0) {
                used.insert(c);
            }
        }
        // cout << "used: ";
        // for (auto c: used) {
        //     cout << c << ", ";
        // }
        // cout << endl;
        int c_now = 1;
        for (int j = 0; j < to[i].size(); j++) {
            if (color[make_pair(i, to[i][j])] == 0) {
                // select color
                while (used.find(c_now) != used.end()) {
                    c_now++;
                }
                color[make_pair(i, to[i][j])] = c_now;
                color[make_pair(to[i][j], i)] = c_now;
                used.insert(c_now);
                c_max = max(c_max, c_now);
            }
        }
    }
    cout << c_max << endl;
    for (auto p: order) {
        cout << color[make_pair(p.first, p.second)] << endl;
    }    
    return 0;
}
