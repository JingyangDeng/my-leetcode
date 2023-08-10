//TLE
//最大的问题：二叉搜索树不平衡导致WT(n) = O(n^2)！
class Node {
    public int val, cnt, size;
    public Node left, right;
    public Node(int x) {val = x; cnt = 1; size = 1;}
}

class TLESolution {
    private Node root = null;
    public int createSortedArray(int[] instructions) {
        int ret = 0;
        for(int n : instructions){
            if(root == null){
                root = new Node(n);
                continue;
            }
            int l = 0, g = 0;
            if(n == root.val){
                root.size++;
                root.cnt++;
                if(root.left != null) g = root.left.cnt;
                if(root.right != null) l = root.right.cnt;
                ret += Math.min(l, g);
                continue;
            }
            Node curNode = root;
            while(true){
                curNode.cnt++;
                if(n == curNode.val) {
                    curNode.size++;
                    if(curNode.left != null) g += curNode.left.cnt;
                    if(curNode.right != null) l += curNode.right.cnt;
                    break;
                }
                if(n < curNode.val){
                    if(curNode.right != null) l += (curNode.right.cnt + curNode.size);
                    else l += curNode.size;
                    if(curNode.left != null) curNode = curNode.left;
                    else {
                        Node node = new Node(n);
                        curNode.left = node;
                        break;
                    }
                } else {
                    if(curNode.left != null) g += (curNode.left.cnt + curNode.size);
                    else g += curNode.size;
                    if(curNode.right != null) curNode = curNode.right;
                    else {
                        Node node = new Node(n);
                        curNode.right = node;
                        break;
                    }
                }
            }
            ret += Math.min(l, g);
        }
        return ret;
    }
}
