#include <iostream>
using namespace std;

struct Node
{
  int data;
  struct Node *ptr;
};

struct Node *front = NULL;
struct Node *rear = NULL;

void enqueue(int);
void dequeue();
void display();

int main()
{
  int i, choice;
  cout << "\n*************************Main Menu*****************************\n";
  cout << "Press 1 for Insertion in Queue.\n";
  cout << "Press 2 for Deletion from Queue.\n";
  cout << "Press 3 to Display Queue.\n";
  cout << "Press 4 to EXIT from Program.\n";
   while (choice != 4)
  {
    cout << "\nEnter Choice. ";
    cin >> choice;
    switch (choice)
    {
    case 1:
      cout << "Enter the element. ";
      cin >> i;
      enqueue(i);
      break;
    case 2:
      dequeue();
      break;
    case 3:
    cout<<"\nDisplaying elements of QUEUE : "<<endl;
      display();
      break;
    case 4:
      cout << "End of the Program.\n";
      exit(0);
      break;
    default:
      cout << "Enter valid choice.\n";
    }

  }
  return 0;
}
void enqueue(int n)
{
  Node *temp = new Node;
  if (temp == NULL)
  {
    cout << "-----OVERFLOW------\n Queue is Full" << endl;
    return;
  }
  temp->data = n;
  temp->ptr = NULL;
  if (front == NULL)
  {
    front = temp;
    rear = temp;
  }
  else
  {
    rear->ptr = temp;
    rear = temp;
  }
  cout << "Inserted element is: " << n << endl;
}

void dequeue()
{
  if (front == NULL)
  {
    cout << "-----UNDERFLOW------\n Queue is Empty" << endl;
    return;
  }
  cout << "Deleted element is: " << front->data << endl;
  if (front == rear)
    front = rear = NULL;
  else
    front = front->ptr;
}

void display()
{
  if (front == NULL)
  {
    cout << "Queue Empty. Underflow." << endl;
    return;
  }
  Node *temp = front;
  while (temp)
  {
    cout << temp->data << " ";
    temp = temp->ptr;
  }
  cout << endl;
}
