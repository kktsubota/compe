# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def maxAncestorDiff(self, root: TreeNode) -> int:
        self.getMaxValueInChildren(root)
        self.getMinValueInChildren(root)

        return self.getMaxDiff(root)

    def getMaxDiff(self, root: TreeNode) -> int:
        if hasattr(root, 'max_diff'):
            return root.max_diff

        if root.max_value is not None:
            v_from_max = abs(root.val - root.max_value)
        else:
            v_from_max = -1
        if root.min_value is not None:
            v_from_min = abs(root.val - root.min_value)
        else:
            v_from_min = -1

        root.max_diff = max(v_from_max, v_from_min)
        ans = root.max_diff
        if root.left is not None:
            ans = max(ans, self.getMaxDiff(root.left))
        if root.right is not None:
            ans = max(ans, self.getMaxDiff(root.right))

        return ans

    def getMaxValueInChildren(self, root: TreeNode) -> int:
        if hasattr(root, 'max_value'):
            return root.max_value
        
        if root.left is None and root.right is None:
            root.max_value = None
            return None

        if root.left is not None:
            v_left_c = self.getMaxValueInChildren(root.left)
            if v_left_c is None:
                v_left = root.left.val
            else:
                v_left = max(root.left.val, v_left_c)
        else:
            v_left = -1
        
        if root.right is not None:
            v_right_c = self.getMaxValueInChildren(root.right)
            if v_right_c is None:
                v_right = root.right.val
            else:
                v_right = max(root.right.val, v_right_c)
        else:
            v_right = -1

        root.max_value = max(v_left, v_right)
        return root.max_value

    def getMinValueInChildren(self, root: TreeNode) -> int:
        if hasattr(root, 'min_value'):
            return root.min_value
        
        if root.left is None and root.right is None:
            root.min_value = None
            return None

        if root.left is not None:
            v_left_c = self.getMinValueInChildren(root.left)
            if v_left_c is None:
                v_left = root.left.val
            else:
                v_left = min(root.left.val, v_left_c)
        else:
            v_left = 10 ** 6
        
        if root.right is not None:
            v_right_c = self.getMinValueInChildren(root.right)
            if v_right_c is None:
                v_right = root.right.val
            else:
                v_right = min(root.right.val, v_right_c)
        else:
            v_right = 10 ** 6

        root.min_value = min(v_left, v_right)
        return root.min_value
