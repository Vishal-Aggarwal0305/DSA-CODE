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
    ListNode * reverse(ListNode * ptr){
        
        if(ptr->next==NULL) return ptr;
        
       ListNode* b= reverse(ptr->next);
        b->next=ptr;
        ptr->next=NULL;
        
        return ptr;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        ListNode* b=head;
        ListNode * a=new ListNode(-1);
        a->next=head;
        
        head=a;
        while(b!=NULL){
            
            ListNode* e=b;
            int z=k-1;
            while(z--&&b!=NULL){
                
                b=b->next;
            }
            if(b!=NULL){
            ListNode * c=b->next;
            b->next=NULL;
         
            ListNode * f=reverse(e);
           // cout<<f->val<<" "<<e->val<<endl;
            a->next=b;
            a=f;
            b=c;
            }
            else{
                a->next=e;
            }
                
            
            
        }
        return head->next;
        
    }
};