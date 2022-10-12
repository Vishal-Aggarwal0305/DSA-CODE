#include <iostream>
using namespace std;

struct node
{
    int dat;
    struct node *next;
};

void display(struct node *ptr)
{
    while (ptr != NULL)
    {
        cout << "The element is" << ptr->dat << endl;
        ptr = ptr->next;
    }
}

int main()
{
    struct node *head;
    struct node *second;
    struct node *third;

    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));

    head->dat = 43;
    head->next = second;
    second->dat = 24;
    second->next = third;
    third->dat = 324;
    third->next = NULL;

    display(head);
    return 0;
}