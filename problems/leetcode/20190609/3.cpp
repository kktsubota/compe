/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        int sum = maxSumToLeaf(root, limit, 0);
        if (sum < limit) {
            root = NULL;
        }
        return root;
    }
    
    int maxSumToLeaf(TreeNode* root, int limit, int sum_value) {
        if (root == NULL) {
            return sum_value;
        } else {
            sum_value += root->val;        
        }
        int sum_left = maxSumToLeaf(root->left, limit, sum_value);
        int sum_right = maxSumToLeaf(root->right, limit, sum_value);

        if (sum_left < limit && sum_right < limit) {
            return max(sum_left, sum_right);        
        } else {
            if (sum_left < limit) {
                root->left = NULL;
                return sum_right;
            }
            if (sum_right < limit) {
                root->right = NULL;
                return sum_left;
            }
            return max(sum_left, sum_right);
        }
    }
};