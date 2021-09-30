/*
// Definition for a Node.
class Node {
    public int val;
    public Node prev;
    public Node next;
    public Node child;
};
*/

//简单的链表操作
//有child进child，没child进next，到null查看stack，空栈返回
class Solution {
    public Node flatten(Node head) {
        Node curNode = head, prevNode = null, tmpNode = null;
        Stack<Node> st = new Stack<>();
        while(curNode != null || !st.empty()){
            if(curNode == null){
                while(!st.empty() && st.peek() == null) st.pop();
                if(st.empty()) break;

                tmpNode = st.pop();
                prevNode.next = tmpNode;
                tmpNode.prev = prevNode;
                curNode = tmpNode;
                continue;
            }

            if(curNode.child == null){
                prevNode = curNode;
                curNode = curNode.next;
                continue;
            }
            
            st.push(curNode.next);
            prevNode = curNode;
            curNode.next = curNode.child;
            curNode.child = null;

            curNode = curNode.next;
            curNode.prev = prevNode;
        }
        return head;
    }
}
