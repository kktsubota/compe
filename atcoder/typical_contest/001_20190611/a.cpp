#include <stack>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <utility>
#include <iterator>

using namespace std;


int main() {
    int H, W;
    cin >> H >> W;
    string row;
    vector<string> mass(H);
    pair<int, int> start;
    for (int i = 0; i < H; i++) {
        cin >> row;
        mass[i] = row;
        int j = (int) row.find('s');
        if (j != string::npos) {
            start = make_pair(i, j);
        }
    }
    stack<pair<int, int>> S;
    set<pair<int, int>> searched;
    S.push(start);
    bool reach = false;
    while (!S.empty()) {
        const pair<int, int> pos = S.top();
        // cout << "(" << pos.first << ", " << pos.second << ")" << endl;
        S.pop();

        if (searched.find(pos) != searched.end()) {
            continue;
        }
        searched.insert(pos);

        if (pos.first < 0 || pos.first >= H) {
            continue;
        }
        if (pos.second < 0 || pos.second >= W) {
            continue;
        }
        if (mass[pos.first][pos.second] == '#') {
            continue;
        }
        if (mass[pos.first][pos.second] == 'g') {
            reach = true;
            break;
        }
        S.push(make_pair(pos.first + 1, pos.second));
        S.push(make_pair(pos.first - 1, pos.second));
        S.push(make_pair(pos.first, pos.second + 1));
        S.push(make_pair(pos.first, pos.second - 1));
    }
    if (reach) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}
