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
class Solution 
{
    public ListNode mergeTwoLists(ListNode Node1, ListNode Node2) 
    {
        ListNode TEMP=new ListNode(0);
        ListNode HEAD=TEMP;
        while(Node1!=null&&Node2!=null)
        {
            if(Node1.val<=Node2.val)
            {
                TEMP.next=Node1;
                Node1=Node1.next;
            }
            else
            {
                TEMP.next=Node2;
                Node2=Node2.next;
            }
            TEMP=TEMP.next;
        }
        if(Node1==null)
        {
            TEMP.next=Node2;
        }
        if(Node2==null)
        {
            TEMP.next=Node1;
        }
        return HEAD.next;
    }
}
