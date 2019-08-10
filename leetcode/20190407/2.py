# depth: log n, num: n//2
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def sumRootToLeaf(self, root: TreeNode) -> int:
        binaries = self.searchBinaries(root)
        base = 10 ** 9 + 7
        ans = 0
        for binary in binaries:
            ans += int(''.join(map(str, binary)), 2)
            ans = ans % base
        return ans

    def searchBinaries(self, root: TreeNode) -> list:
        ret_list = list()
        if root.left is None and root.right is None:
            return [[root.val]]

        if root.left is not None:
            binaries = self.searchBinaries(root.left)
            ret_list += [[root.val] + binary for binary in binaries]
        if root.right is not None:
            binaries = self.searchBinaries(root.right)
            ret_list += [[root.val] + binary for binary in binaries]
            
        return ret_list
        