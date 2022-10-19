#include<iostream>
#include<cstdlib>
#include<cmath>

using namespace std;

struct Node{
    float info;
    struct Node *link;
};

void Bucketsort(float *,int);
void Printarray(float *,int);
Node *insertion_sort(Node *);
Node *insert_sort(Node *,Node *);

int main(){
    int i,n;
    float A[20];
    cout<<"Enter the value of n : ";
    cin>>n;
    printf("Enter the %d array elements:\n",n);
    for(i=0;i<n;i++){
        printf("A[%d] = ",i);
        cin>>*(A+i);
    }
    Bucketsort(A,n);
    Printarray(A,n);
    return 0;
}

void Printarray(float *A,int n){
    for(int i=0;i<n;i++){
        cout<<A[i]<<" ";
    }
}

Node *insert_sort(Node *newnode,Node *sorted){
    if(sorted==NULL||sorted->info>=newnode->info){
        newnode->link=sorted;
        sorted=newnode;
    }else{
        Node *curr=sorted;
        while(curr->link!=NULL && curr->link->info<newnode->info){
            curr=curr->link;
        }
        newnode->link=curr->link;
        curr->link=newnode;
    }
    return sorted;
}

Node *insertion_sort(Node *head){
    Node *ptr=head,*sorted=NULL;
    while(ptr!=NULL){
        Node *next=ptr->link;
        sorted=insert_sort(ptr,sorted);
        ptr=next;
    }
    return sorted;
}

void Bucketsort(float *A,int n){
    Node *B[n-1];
    int j;
    for(int i=0;i<n;i++){
        B[i]=NULL;
    }
    for(int i=0;i<n;i++){
        j=floor(n*A[i]);
        Node *ptr=(Node *)malloc(sizeof(Node));
        ptr->info=A[i];
        ptr->link=B[j];
        B[j]=ptr;
    }
    for(int i=0;i<n;i++){
        B[i]=insertion_sort(B[i]);
    }
    int i=0;
    int t=0;
    while(i<n){
        for(int j=0;j<n;j++){
            if(B[j]==NULL){
                continue;
            }else{
                Node *ptr=B[j];
                while(ptr!=NULL){
                    A[i]=ptr->info;
                    i++;
                    ptr=ptr->link;
                }
            }
        }
    }
}