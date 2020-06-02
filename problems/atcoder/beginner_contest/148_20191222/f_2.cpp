#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;


vector<int> get_distance(vector<vector<int>> to, int u) {
    int N = (int) to.size();
    vector<int> dist_from_u(N, 2 * N);
    queue<pair<int, int>> que;
    que.push(make_pair(u, 0));
    while (!que.empty()) {
        auto node = que.front();
        int d = node.second;
        que.pop();
        // cout << que.size() << " " << node.first << node.second << dist_from_u[node.first] << endl;
        // already visited
        if (dist_from_u[node.first] != (2 * N)) {
            continue;
        }
        d = min(dist_from_u[node.first], d);
        dist_from_u[node.first] = d;

        // next points
        d++;        
        for (int target: to[node.first]) {
            que.push(make_pair(target, d));
        }
    }
    return dist_from_u;
}

int main(int argc, char const *argv[])
{
    int N, u, v;
    cin >> N >> u >> v;
    u--; v--;
    vector<int> A(N - 1), B(N - 1);
    vector<vector<int>> to(N);
    for (int i = 0; i < (N - 1); i++) {
        cin >> A[i] >> B[i];
        A[i]--; B[i]--;
        to[A[i]].push_back(B[i]);
        to[B[i]].push_back(A[i]);
    }
    vector<int> dist_from_v = get_distance(to, v);

    // dist from u
    int N = (int) to.size();
    vector<int> time(N, -1);
    queue<pair<int, int>> que;
    que.push(make_pair(u, 0));
    while (!que.empty()) {
        auto node = que.front();
        int d = node.second;
        que.pop();
        // cout << que.size() << " " << node.first << node.second << time[node.first] << endl;
        // already visited
        if (time[node.first] != -1) {
            continue;
        }
        d = min(time[node.first], d);
        // dist is even
        if (dist_from_v[u] % 2 == 0) {
            if (dist_from_v[node.first] > d) 
                time[node.first] = dist_from_v[node.first] - 1;
            } else {
                time[node.first] = 
                
            }            
        } else {
            if (dist_from_v[node.first] > d) {
                time[node.first] = dist_from_v[node.first] - 1;
            } else {

            }
        }

        // next points
        if (dist_from_v[node.first] <= d) {
            d = -1;            
        } else {
            d++;
        }
        for (int target: to[node.first]) {
            que.push(make_pair(target, d));
        }
    }

    // cout << "dist from v: ";
    // for (auto e: dist_from_v) {
    //     cout << e << ", ";
    // }
    // cout << endl;
    vector<int> dist_from_u = get_distance(to, u);
    // cout << "dist from u: ";
    // for (auto e: dist_from_u) {
    //     cout << e << ", ";
    // }
    // cout << endl;
    if (dist_from_u[v] % 2 == 0) {

    } else {

    }
    // furthest point from v (that u can go)
    int point;
    int d = 0;
    for (int i = 0; i < N; i++) {
        if (dist_from_u[i] < dist_from_v[i]) {
            if (d < dist_from_v[i]) {
                point = i;
                d = dist_from_v[i];
            }
        }
    }
    // not found
    if (d == 0) {
        point = to[u][0];
        if (dist_from_v[point] == 0) {
            d = 0;
        } else {
            d = 1;
        }
    }
    // cout << point << endl;
    if (abs(dist_from_u[point] - d) % 2 == 0) {
        cout << d << endl;
    } else {
        cout << max((d - 1), 0) << endl;
    }
    return 0;
}
