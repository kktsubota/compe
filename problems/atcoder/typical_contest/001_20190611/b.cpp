#include <iostream>
#include <vector>

using namespace std;

class UnionFind {
private:
    int n;
    vector<int> root;
    vector<int> depth;
public:
    UnionFind(int n);
    void unite(int k, int l);
    int find(int k);
};

UnionFind::UnionFind(int n)
{
    this->n = n;
    for (int i = 0; i < n; i++) {
        this->root.push_back(i);
        this->depth.push_back(1);
    }
    return;
}
void UnionFind::unite(int k, int l) {
    int root_of_k = find(k);
    int root_of_l = find(l);

    if (root_of_k == root_of_l) {
        return;
    }
    if (depth[root_of_k] <= depth[root_of_l]) {
        root[root_of_k] = root_of_l;
        if (depth[root_of_k] == depth[root_of_l]) {
            depth[root_of_k]++;
        }
    } else {
        root[root_of_l] = root_of_k;
    }
    return;
}

int UnionFind::find(int k) {
    if (root[k] != k) {
        root[k] = find(root[k]);
    }
    return root[k];
}


int main(int argc, char const *argv[])
{
    int n, q;
    cin >> n >> q;
    UnionFind tree = UnionFind(n);
    int p, a, b;
    for (int i = 0; i < q; i++) {
        cin >> p >> a >> b;
        // connect
        if (p == 0) {
            tree.unite(a, b);
        } else { // judge
            if (tree.find(a) == tree.find(b)) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }
    return 0;
}

