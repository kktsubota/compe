#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


ll dfs(vector<vector<bool>>& room, ll a, ll b, ll index) {
    if (a == 0LL && b == 0LL) {
        return 1LL;
    }
    if (a < 0 || b < 0) {
        return 0LL;
    }
    ll y = index / room[0].size();
    ll x = index % room[0].size();
    if (room[y][x]) {
        return dfs(room, a, b, index + 1);
    } else {
        // use b
        room[y][x] = true;
        ll vb = dfs(room, a, b - 1, index + 1);
        room[y][x] = false;

        // use a
        // room[y][x-1], room[y-1][x] is already filled

        // room[y][x+1] is empty
        ll va1 = 0LL;
        if (x + 1 < room[y].size()) {
            if (!room[y][x+1]) {
                room[y][x] = true;
                room[y][x+1] = true;
                va1 = dfs(room, a - 1, b, index + 1);
                room[y][x] = false;
                room[y][x+1] = false;
            }
        }
        // room[y+1][x] is empty
        ll va2 = 0LL;
        if (y + 1 < room.size()) {
            if (!room[y+1][x]) {
                room[y][x] = true;
                room[y+1][x] = true;
                va2 = dfs(room, a - 1, b, index + 1);
                room[y][x] = false;
                room[y+1][x] = false;
            }
        }
        return va1 + va2 + vb;
    }

   
}
int main() {
    ll h, w, a, b;
    cin >> h >> w >> a >> b;
    vector<vector<bool>> room(h, vector<bool>(w, false));
    cout << dfs(room, a, b, 0LL) << endl;
    return 0;
}