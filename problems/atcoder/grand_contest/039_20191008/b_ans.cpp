#include <vector>
#include <iostream>
#include <queue>
#include <utility>
#include <string>
#include <algorithm>

using namespace std;

bool is_bipartite(vector<vector<int>> S) {
    int N = (int) S.size();
    // -1: not assigned, 0/1: assigned
    vector<int> part(N, -1);
    queue<pair<int, int>> que;

    // init
    // node_num=0, part=0
    que.push(make_pair(0, 0));

    // traverse
    while (!que.empty()) {
        pair<int, int> node = que.front();
        // cout << node.first << ", " << node.second << endl;
        que.pop();
        if (part[node.first] != -1) {
            // inconsistency
            if (part[node.first] != node.second) {
                return false;
            } else {
                continue;
            }
        }
        part[node.first] = node.second;
        for (int target = 0; target < N; target++) {
            if (S[node.first][target] == 1) {
                que.push(make_pair(target, 1 - node.second));
            }
        }
    }
    return true;
}

int calc_diameter(vector<vector<int>> S) {
    int N = (int) S.size();
    const int max_value = N * N * N;
    vector<vector<int>> distance(N, vector<int>(N, max_value));
    // init
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (S[i][j]) {
                distance[i][j] = 1;
            } else if (i == j) {
                distance[i][j] = 0;
            }
        }
    }
    // update values
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                // distance[k] denotes using nodes equal to or smaller than k as a checkpoint.
                // distance[k][i][j]
                // = min(distance[k-1][i][j],
                //       distance[k-1][i][k] + distance[k-1][k][j]) via k
                // using better value for distance[i][j] causes no trouble.
                distance[i][j] = min(distance[i][k] + distance[k][j], distance[i][j]);
            }
        }
    }
    int diameter = -1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            // no such path
            if (distance[i][j] >= max_value) {
                continue;
            }
            diameter = max(diameter, distance[i][j]);
        }
    }
    return diameter;
}

int main(int argc, char const *argv[]) {
    int N;
    cin >> N;
    vector<vector<int>> S(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < N; j++) {
            S[i][j] = s[j] - '0';
        }
    }
    if (!is_bipartite(S)) {
        cout << -1 << endl;
    } else {
        cout << calc_diameter(S) + 1 << endl;
    }
    return 0;
}
