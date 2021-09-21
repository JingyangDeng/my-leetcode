/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */

//简单遍历
class Solution {
    public ListNode[] splitListToParts(ListNode head, int k) {
        ListNode[] ret = new ListNode[k];
        int len = 0;
        ListNode curNode = head;
        while(curNode != null){
            len++;
            curNode = curNode.next;
        }
        int avg = len / k;
        int sur = len % k;

        int cnt;
        ListNode headNode = head, tmpNode = null;
        curNode = head;
        for(int i = 0; i < k; i++){
            if(headNode == null){
                ret[i] = null;
                continue;
            }
            headNode = curNode;
            cnt = avg;
            if(sur-- > 0) cnt++;
            while(--cnt > 0) curNode = curNode.next;
            if(curNode != null) {
                tmpNode = curNode.next;
                curNode.next = null;
            }
            ret[i] = headNode;
            curNode = tmpNode;
        }
        return ret;
    }
}
