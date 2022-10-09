#include "bits/stdc++.h"
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(){
        this->data=0;
        this->next=NULL;
    }
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};
void insertAtHead(Node* &head, int data){
    Node *temp=new Node(data);
    temp->next=head;
    head=temp;
}
void insertAtEnd(Node* &head, int data){
    Node *node1=new Node(data);
    if(head == NULL){
        head=node1;
        return;
    }
    Node* temp=head;
    while(temp->next!=NULL)
        temp=temp->next;
    temp->next=node1; 
    // tail=temp;
}
void insertAtposition(Node* &head,int pos, int data){
    Node* temp=head;
    if(pos==1){
        insertAtHead(head,data);
    }
    int cnt=1;
    while(cnt<pos-1){
        temp=temp->next;
        cnt++;
    }
    if(temp->next==NULL){
        insertAtEnd(head,data);
        return;
    }
    Node *node1=new Node(data);
    node1->next=temp->next;
    temp->next=node1;
}

void print(Node* &head){
    Node* temp=head;
    if (head == NULL) {
        cout << "List empty" << endl;
        return;
    }
    while (temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
    

}
int main(){
    Node* head = NULL;
    insertAtEnd(head,1);
    insertAtEnd(head,2);
    insertAtEnd(head,3);
    insertAtEnd(head,4);
    insertAtposition(head,3,7);
    print(head);
}

