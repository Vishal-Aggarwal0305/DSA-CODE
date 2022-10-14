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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        
        priority_queue<pair<int,ListNode*>>q;
        
        
        for(auto i :lists){
            
            if(i!=NULL)
            q.push({-1*(i->val),i});
            
        }
        ListNode * head=NULL;
        ListNode* a=NULL;
        while(!q.empty()){
            
            auto x=q.top();
            q.pop();
            cout<<x.first<<endl;
            
            if(a==NULL){
               a=x.second; 
                
                head=a;
            }
            else{
                a->next=x.second;
                a=x.second;
              
            }
            
            if(x.second->next!=NULL){
                q.push({-1*(x.second->next->val),x.second->next});
            }
            a->next=NULL;
            
            
            
        }
        
        return head;
        
    }
};