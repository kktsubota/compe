#include <unordered_map>
#include <unordered_set>


class Solution {
public:
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        vector<int> ans(N, -1);
        unordered_map<int, unordered_set> inverse_index;
        for (auto path: paths) {
            int beg = path[0] - 1;
            int end = path[1] - 1;
            unordered_map[beg].insert(end);
            unordered_map[end].insert(beg);            
        }
        
        for (int i = 0; i < N; i++) {
            # connected set
            auto connected = inverse_index[i];
            if (ans[i] == -1) {
                if ()
                ans[i] = 1;
            }
            for (auto idx: connected) {
                
            }
            
        }
        
    }
};


#include <unordered_map>
#include <unordered_set>


class Solution {
public:
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        vector<int> ans(N, -1);
        unordered_map<int, unordered_set> adj;
        for (auto path: paths) {
            int beg = path[0] - 1;
            int end = path[1] - 1;
            adj[beg].insert(end);
            adj[end].insert(beg);            
        }
        unordered_set<int> index = {0, .., N - 1};
        int target = -1;
        while (!index.empty()) {
            if (target == -1) {
                // any color
                target = index.pop();
                ans[target] = 1;
            } else {
                // assign not adjacent color
                unordered_set<int> candidate = {1, 2, 3, 4};
                auto connected = adj[target];
                for (int idx: connected) {
                    if (ans[idx] != -1) {
                        candidate.remove(ans[idx]);
                    }
                }
                int color = candidate.pop();
                ans[target] = color;
            }    
            # connected set
            # contains ? idx : -1
            auto connected = adj[target];
            target = -1;
            for (int idx: connected) {
                if (ans[i] != -1) {
                    target = idx;
                    break;
                }                
            }
        }
    }
};



#include <unordered_map>
#include <unordered_set>


class Solution {
public:
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        vector<int> ans(N, -1);
        unordered_map<int, unordered_set> adj;
        for (auto path: paths) {
            int beg = path[0] - 1;
            int end = path[1] - 1;
            adj[beg].insert(end);
            adj[end].insert(beg);            
        }
        for (int i = 0; i < N; i++) {
            // assign not adjacent color
            unordered_set<int> candidate = {1, 2, 3, 4};
            auto connected = adj[i];
            for (int idx: connected) {
                if (ans[idx] != -1) {
                    candidate.remove(ans[idx]);
                }
            }
            int color = candidate.pop();
            ans[i] = color;
        }
        return ans;
    }
};

#include <unordered_map>
#include <unordered_set>


class Solution {
public:
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        vector<int> ans(N, -1);
        unordered_map<int, unordered_set<int>> adj;
        for (auto path: paths) {
            int beg = path[0] - 1;
            int end = path[1] - 1;
            adj[beg].insert(end);
            adj[end].insert(beg);            
        }
        for (int i = 0; i < N; i++) {
            // assign not adjacent color
            unordered_set<int> candidate = {1, 2, 3, 4};
            auto connected = adj[i];
            for (int idx: connected) {
                if (ans[idx] != -1) {
                    candidate.erase(ans[idx]);
                }
            }
            int color = *candidate.begin();
            candidate.erase(candidate.begin());
            ans[i] = color;
        }
        return ans;
    }
};