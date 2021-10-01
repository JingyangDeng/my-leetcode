//执行用时：7 ms, 在所有 Java 提交中击败了100.00% 的用户
//内存消耗：38.7 MB, 在所有 Java 提交中击败了91.43% 的用户 
//
//首先建立二叉查找树。可对两个子树求得结果lret和rret，通过计算组合数将其整合：
//ret = lret * rret * c(lcnt + rcnt, lcnt) 其中lcnt rcnt 为子树节点个数
//在计算组合数模p时，使用扩展欧几里得算法求逆元，每次复杂度为O(logn)。
//由master定理，复杂度为O(n(logn)^2)，此题主要需要将计算组合数取模限制在尽量低的复杂度。

//事实上，存在一种方法，只需进行O(n)的预处理便可在O(1)时间内计算组合数
//建树的过程也可通过并查集优化至O(n alpha(n))，这样一来复杂度便为O(n alpha(n))
//详见:https://leetcode-cn.com/problems/number-of-ways-to-reorder-array-to-get-same-bst/solution/jiang-zi-shu-zu-zhong-xin-pai-xu-de-dao-tong-yi-2/ 
class Node {
    public int val, cnt;
    public Node left, right;
    public Node(int x){val = x; cnt = 1;}
}

class Solution {
    private Node root;
    private int mod = 1000000007;
    public int numOfWays(int[] nums) {
        buildTree(nums);
        Node curNode = root;
        return merge(root) - 1;
    }

    private void buildTree(int[] nums){
        root = new Node(nums[0]);
        if(nums.length == 1) return;
        for(int i = 1; i < nums.length; i++){
            root.cnt++;
            Node curNode = root;
            while(true){
                if(nums[i] < curNode.val){
                    if(curNode.left != null) {
                        curNode = curNode.left;
                        curNode.cnt++;
                    }
                    else {
                        curNode.left = new Node(nums[i]);
                        break;
                    }
                } else {
                    if(curNode.right != null) {
                        curNode = curNode.right;
                        curNode.cnt++;
                    }
                    else {
                        curNode.right = new Node(nums[i]);
                        break;
                    }
                }
            }
        }
        return;
    }

    private int merge(Node root){
        if(root.left == null && root.right == null) return 1;
        if(root.left == null) return merge(root.right);
        if(root.right == null) return merge(root.left);
        int leftRet = merge(root.left), rightRet = merge(root.right);
        int leftCnt = root.left.cnt, rightCnt = root.right.cnt;
        long ret = 1;
        ret *= leftRet; ret %= mod;
        ret *= rightRet; ret %= mod;
        ret *= C(leftCnt + rightCnt, Math.min(leftCnt, rightCnt)); ret %= mod;
        return (int)ret;
    }

    private int C(int m, int n){
        long ret = 1;
        for(int x = m-n+1; x <= m; x++){
            ret *= x; ret %= mod;
        }
        for(int x = 1; x <= n; x++){
            ret *= exgcd(x, mod, 1, 0); ret %= mod;
        }
        if(ret < 0) ret += mod;
        return (int)ret;
    }

    private long exgcd(long r1,long r2,long x1,long x2){
        long qr = r1 / r2;
        long r = r1 % r2;
        long x = x1 - qr * x2;
        if(r == 1){
            return x;
        }
        return exgcd(r2, r, x2, x);
    }
}
