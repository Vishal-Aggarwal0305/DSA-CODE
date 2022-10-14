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
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
       ListNode* a=l1,*b=l2;
        
      int  x=0;
        while(a->next!=NULL&&b->next!=NULL){
            
            int y=a->val;
          a->val=(a->val+b->val+x)%10;
            
            x=(y+b->val+x)/10;
            
              
              a=a->next;
            b=b->next;
            
            
        }
        //ut<<x<<endl;
        if(a->next==NULL){
          int  y=a->val;
            a->val=(a->val+b->val+x)%10;
            x=(y+b->val+x)/10;
            b=b->next;
            a->next=b;
          //out<<x<<endl;
            while(b!=NULL&&x!=0){
                int z=b->val;
                b->val=(b->val+x)%10;
                        
                        x=(z+x)/10;
                b=b->next;
            }
        }
        else if(b->next==NULL){
            //ut<<x<<endl;
           int  y=a->val;
            a->val=(a->val+b->val+x)%10;
            x=(y+b->val+x)/10;
            
        a=a->next;
            while(a!=NULL&&x!=0){
                int z=a->val;
                a->val=(a->val+x)%10;
                        
                        x=(z+x)/10;
                a=a->next;
            }
            
        }
        ListNode * e=l1;
        while(e->next!=NULL){
            
            e=e->next;
        }
        
        
    if(x!=0){
       
       ListNode * d=new ListNode(x);
                   e->next=d;
   }
       
        
        return l1;
    }
};