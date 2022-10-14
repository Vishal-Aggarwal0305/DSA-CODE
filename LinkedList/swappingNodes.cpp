/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        
       int length=0; 
    ListNode*ptr=head;
        ListNode*a;
        while(ptr!=NULL){
            
            if(length==k-1){
                
                a=ptr;
            }
            ptr=ptr->next;
            length++;
           
        }
        ptr=head;
        ListNode*b;
        int x=length-k;
        while(x--){
            ptr=ptr->next;
        }
        b=ptr;
        swap(a->val,b->val);
        return head;
        
    }
};