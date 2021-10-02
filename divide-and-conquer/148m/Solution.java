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
//执行用时：5 ms, 在所有 Java 提交中击败了99.33% 的用户
//内存消耗：42.9 MB, 在所有 Java 提交中击败了96.55% 的用户
//
//归并排序
class Solution {
    public ListNode sortList(ListNode head) {
        int n = 0;
        ListNode curNode = head;
        while(curNode != null) {
            n++;
            curNode = curNode.next;
        }
        return mergeSort(head, n);
    }

    private ListNode mergeSort(ListNode head, int n){
        if(n == 0) return null;
        if(n == 1) return head;
        int n1 = n >> 1;
        int n2 = (n + 1) >> 1;
        ListNode curNode = head;
        for(int i = 1; i < n1; i++) curNode = curNode.next;
        ListNode head2 = mergeSort(curNode.next, n2);
        curNode.next = null;
        ListNode head1 = mergeSort(head, n1);
        
        ListNode ret;
        if(head1.val < head2.val){
            ret = head1;
            head1 = head1.next;
        } else {
            ret = head2;
            head2 = head2.next;
        }
        curNode = ret;
        while(head1 != null && head2 != null){
            if(head1.val < head2.val) {
                curNode.next = head1;
                head1 = head1.next;
            } else {
                curNode.next = head2;
                head2 = head2.next;
            }
            curNode = curNode.next;
        }
        if(head1 == null){
            curNode.next = head2;
        } else {
            curNode.next = head1;
        }
        return ret;
    }
}
