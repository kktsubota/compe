class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        vector<int> ans;
        int layer = 0;
        int temp; 
        for (; layer <= 20; layer++) {
            temp = factorial(2, layer);
            if (temp <= label && label < factorial(2, layer+1)) {
                break;
            }
        }
        // 6th in the layer
        int order = label - temp;
        while (true) {
            ans.push_back(temp + order);
            if (layer == 0) {
                break;
            }
            // 1th in the layer (inv)
            int order_inv = temp - order - 1;
            // in the previous layer
            order = order_inv / 2;
            layer--;
            temp /= 2;
        }
        reverse(ans.begin(), ans.end());
        return ans;            
    }
    
    int factorial(int base, int n) {
        if (n == 0) {
            return 1;
        } else {
            return factorial(base, n - 1) * base;
        }
    }
};