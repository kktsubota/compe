#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


void dfs(const int node, const vector<vector<int>>& edges, const vector<int>& colors, vector<int>& color_cnt, vector<bool>& is_accessed, vector<int>& answer) {
    // もし参照渡しを使わなければ呼び出しごとにコピーが発生する
    if (is_accessed[node]) {
        return;
    }
    int color = colors[node];
    is_accessed[node] = true;
    if (color_cnt[color] == 0) {
        answer.push_back(node);
    }
    color_cnt[color]++;
    for (int to: edges[node]) {
        if (is_accessed[to]) {
            continue;
        }
        dfs(to, edges, colors, color_cnt, is_accessed, answer);
    }
    color_cnt[color]--;
    return;
}


int main() {
    int n;
    cin >> n;
    vector<int> colors(n);
    for (int i = 0; i < n; i++) {
        cin >> colors[i];
        colors[i]--;
    }
    vector<vector<int>> edges(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    vector<int> answer;
    vector<bool> is_accessed(n, false);
    vector<int> color_cnt(100001, 0);

    dfs(0, edges, colors, color_cnt, is_accessed, answer);

    // O(n log n) operation
    sort(answer.begin(), answer.end());
    for (auto ans: answer) {
        cout << (ans + 1) << endl;
    }
    return 0;
}