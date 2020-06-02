#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    int N, Q;
    cin >> N >> Q;
    vector<vector<int>> to(N);
    vector<int> score(N, 0);
    for (int i = 1; i < N; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        to[a].push_back(b);
    }
    
    for (int i = 0; i < Q; i++) {
        int p, x;
        cin >> p >> x;
        p--;
        score[p] += x;
    }
    // cout << "store input" << endl;
    queue<int> que;
    que.push(0);
    while (!que.empty()) {
        // cout << "que size: " << que.size() << endl;
        int node = que.front();
        // cout << "node: " << node << endl;
        que.pop();
        // cout << "childs: ";
        for (auto child: to[node]) {
            score[child] += score[node];
            que.push(child);
            // cout << child << ", ";
        }
        // cout << endl;
    }
    for (int i = 0; i < N; i++) {
        cout << score[i];
        if (i != N - 1) {
            cout << " ";
        } else {
            cout << endl;
        }
    }
    return 0;
}
