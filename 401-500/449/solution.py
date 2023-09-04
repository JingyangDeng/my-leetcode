# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
# 二叉搜索树先根遍历
class Codec:
    
    def _dfs(self, root):
        if not root:
            return
        self._container.append(str(root.val))
        self._dfs(root.left)
        self._dfs(root.right)
    
    def _construct(self, i, j):
        #print(i, j)
        if i >= j:
            return None
        root = TreeNode(int(self._container[i]))
        k = i
        while k < j and int(self._container[i]) >= int(self._container[k]):
            k += 1
        root.left = self._construct(i + 1, k)
        root.right = self._construct(k, j)
        return root

    def serialize(self, root: Optional[TreeNode]) -> str:
        """Encodes a tree to a single string.
        """
        self._container = []
        self._dfs(root)
        return ','.join(self._container)

    def deserialize(self, data: str) -> Optional[TreeNode]:
        """Decodes your encoded data to tree.
        """
        if not data:
            return None
        self._container = data.split(',')
        #print(self._container)
        return self._construct(0, len(self._container))

# Your Codec object will be instantiated and called as such:
# Your Codec object will be instantiated and called as such:
# ser = Codec()
# deser = Codec()
# tree = ser.serialize(root)
# ans = deser.deserialize(tree)
# return ans
