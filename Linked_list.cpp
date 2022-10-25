#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data; // stores data
        next = NULL;       // stores the address of other node
    }
};
void insertathead(Node *&head, int d)
{
    Node *temp;
    temp = new Node(d);
    temp->next = head;
    head = temp;
}

void insertattail(Node *&tail, int d)
{
    while (tail->next != NULL)
    {
        tail = tail->next;
    }
   if(tail->next == NULL)
   {
     
        Node *temp;
        temp = new Node(d); // creating a new node (temp)
        tail->next = temp;
        tail = temp;
    
   }
}

void insertatposition(Node *&head, Node *&tail, int position, int d)
{
    if (position == 1)
    {
        insertathead(head, d);
        return;
    }
    Node *Temp = head;
    int count = 1;
    while (count < position - 1)
    {
        Temp = Temp->next;
        count++;
    }
    if (Temp->next == NULL)
    {
        insertattail(tail, d);
        return;
    }
    Node *Nodetoinsert = new Node(d);
    Nodetoinsert->next = Temp->next;
    Temp->next = Nodetoinsert;
}

void print(Node *&head)
{
    Node *temp;
    temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        cout << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Node *node1;
    node1 = new Node(34);
    print(node1);
    Node *head = node1;
    Node *tail = node1;
    insertathead(head, 42);
    print(head);
    insertattail(tail,87);
    insertattail(tail, 15);
    print(head);
    insertatposition(head, tail, 3, 99);
    print(head);
    cout << endl;
    cout << "Head: " << head->data << endl;
    cout << "Tail: " << tail->data << endl;
    return 0;
}
