#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;


class Node {
private:
    int value;
    vector<Node> child;
public:
    Node(int value) {
        this-> value = value;
    }
    void addChild(Node node) {
        child.push_back(node);
    }
};


int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    vector<Node> nodes(n);
    for (int i = 0; i < n; i++) {
        nodes[i] = Node(i);
    }
    Node root = nodes[0];
    for (int n_split = 1; n_split < n; n_split++) {
        vector<vector<Node>> parts = split(nodes, n_split);
        for (auto part: parts) {
            vector<vector<int>> trees = make_trees(part);
        }

    }
    root.addChild

    return 0;
}

