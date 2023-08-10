/*
// Definition for a QuadTree node.
class Node {
    public boolean val;
    public boolean isLeaf;
    public Node topLeft;
    public Node topRight;
    public Node bottomLeft;
    public Node bottomRight;

    
    public Node() {
        this.val = false;
        this.isLeaf = false;
        this.topLeft = null;
        this.topRight = null;
        this.bottomLeft = null;
        this.bottomRight = null;
    }
    
    public Node(boolean val, boolean isLeaf) {
        this.val = val;
        this.isLeaf = isLeaf;
        this.topLeft = null;
        this.topRight = null;
        this.bottomLeft = null;
        this.bottomRight = null;
    }
    
    public Node(boolean val, boolean isLeaf, Node topLeft, Node topRight, Node bottomLeft, Node bottomRight) {
        this.val = val;
        this.isLeaf = isLeaf;
        this.topLeft = topLeft;
        this.topRight = topRight;
        this.bottomLeft = bottomLeft;
        this.bottomRight = bottomRight;
    }
};
*/

//递归建树，每次判断是否合并
class Solution {
    public Node construct(int[][] grid) {
        int n = grid.length;
        return buildTree(grid, 0, n, 0, n);
    }
    private Node buildTree(int[][] grid, int left, int right, int top, int bottom){
        //System.out.println(left + "" + right +"" +top+"" + bottom);
        if(right == left + 1) return new Node(grid[top][left] == 1, true);
        Node tl = buildTree(grid, left, (left + right) >> 1, top, (top + bottom) >> 1);
        Node tr = buildTree(grid, (left + right) >> 1, right, top, (top + bottom) >> 1);
        Node bl = buildTree(grid, left, (left + right) >> 1, (top + bottom) >> 1, bottom);
        Node br = buildTree(grid, (left + right) >> 1, right, (top + bottom) >> 1, bottom);
        //System.out.println(tl.val + "" + tr.val + "" +bl.val+""+br.val);
        if(tl.isLeaf && tr.isLeaf && bl.isLeaf && br.isLeaf){
            if((tl.val == tr.val) && (tl.val == bl.val) && (tl.val == br.val)) return new Node(tl.val, true);
        }
        return new Node(true, false, tl, tr, bl, br);
    }
}
