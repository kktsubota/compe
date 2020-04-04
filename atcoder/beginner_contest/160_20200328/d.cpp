#include <bits/stdc++.h>

using namespace std;


int main(int argc, char const *argv[])
{
    int n, x, y;
    int inf = 1001001;
    cin >> n >> x >> y;
    x--; y--;
    vector<vector<int>> adj(n);

    for (int i = 0; i < n; i++) {
        if (i - 1 >= 0) {
            adj[i].push_back(i - 1);
        }
        if (i + 1 < n) {
            adj[i].push_back(i + 1);
        }
    }
    adj[x].push_back(y);
    adj[y].push_back(x);

    vector<vector<int>> distance(n, vector<int>(n, inf));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // if (i < x && j < x) {
            //     distance[i][j] = abs(i - j);
            // } else if (i < x && x <= j && j < y) {
            distance[i][j] = min(abs(i - j), abs(x - i) + 1 + abs(y - j));
        }
    }
    vector<int> counts(n, 0);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int dist = distance[i][j];
            counts[dist]++;
        }
    }
    for (int i = 1; i < n; i++) {
        cout << counts[i] << endl;
    }
    return 0;
}
