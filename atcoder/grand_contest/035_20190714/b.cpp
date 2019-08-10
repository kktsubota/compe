#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;


int main(int argc, char const *argv[]) {
    int n, m;
    cin >> n >> m;
    vector<int> a(m), b(m);
    unordered_map<int, unordered_set<int>> edge;
    for (int i = 0; i < m; i++) {
        cin >> a[i] >> b[i];
        a[i]--; b[i]--;
        edge[a[i]].insert(b[i]);
        edge[b[i]].insert(a[i]);
    }
    for (auto from, to: edge) {
        if (to.size() & 1 == 0) {
            edge.erase(from);
        } else {
            edge[from]
        }
    }
    return 0;
}

