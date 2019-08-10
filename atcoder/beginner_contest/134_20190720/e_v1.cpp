#include <algorithm>
#include <iostream>
#include <set>
#include <unordered_set>
#include <vector>
 
using namespace std;
 
 
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<int> As(n);
    for (int i = 0; i < n; i++) {
        cin >> As[i];
    }
    set<int> indices;
    for (int i = 0; i < n; i++) {
        indices.insert(i);
    }
    int count = 0;
    while (!indices.empty()) {
        vector<int> remove;
        int a = -1;
        for (auto idx: indices) {
            if (a == -1) {
                a = As[idx];
                remove.push_back(idx);
            } else {
                if (a < As[idx]) {
                    a = As[idx];
                    remove.push_back(idx);
                }
            }
            for (auto idx_rm: remove) {
                indices.erase(idx_rm);
            }
        }
        count++;
    }
    cout << count << endl;
    return 0;
}