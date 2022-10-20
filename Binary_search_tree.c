#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *Newnode(int data)
{
    struct Node *node1 = (struct Node *)malloc(sizeof(struct Node));
    if (node1 != NULL)
    {
        node1->data = data;
        node1->left = NULL;
        node1->right = NULL;
    }
    else
    {
        printf("Overflow!!!");
            exit(0);
    }
    return node1;
}

struct Node *insert(struct Node *node, int data)
{
    if (node == NULL)
        return Newnode(data);

    if (data < node->data)
        node->left = insert(node->left, data);
    else
        node->right = insert(node->right, data);
    return node;
}

int smallestbst(struct Node *root)
{
    if (root->left == NULL)
        return root->data;
    smallestbst(root->left);
}

int largestbst(struct Node *root)
{
    if (root->right == NULL)
        return root->data;
    largestbst(root->right);
}

struct Node *searchanodebst(struct Node *root, int data)
{struct Node *ptr;
    while (root != NULL)
    {
        if (data > root->data)
            root = root->right;
        else if (data < root->data)
            root = root->left;
        else
            return ptr;
    }
    return NULL;
}

struct Node *deleteanodebst(struct Node *root, int data)
{
    struct Node *cur = root;
    struct Node *prev = NULL;

    if (cur == NULL)
    {
        printf("Data not found!!!");
        return root;
    }

    while (cur != NULL && cur->data != data)
    {
        prev = cur;
        if (data < cur->data)
            cur = cur->left;
        else
            cur = cur->right;
    }

    if (cur->left == NULL || cur->right == NULL)
    {
        struct Node *cur1;
        if (cur->left == NULL)
        {
            cur1 = cur->right;
        }
        else
        {
            cur1 = cur->left;
        }
        if (prev == NULL)
            return cur1;

        if (cur == prev->left)
            prev->left = cur1;
        else
            prev->right = cur1;
        free(cur);
    }
    else
    {
        struct Node *p = NULL;
        struct Node *temp;

        temp = cur->right;
        while (temp->left != NULL)
        {
            p = temp;
            temp = temp->left;
        }
        if (p != NULL)
            p->left = temp->right;
        else
            cur->right = temp->right;
        cur->data = temp->data;
        free(temp);
    }
    return root;
}

void inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d\t", root->data);
        inorder(root->right);
    }
}

int main()
{
    struct Node *root = NULL, *temp;
    int data, ch, small, large,n;
    printf("Enter root data: ");
    scanf("%d", &data);
    root = insert(root, data);
    do
    {
        printf("1. Create  binary search tree and Enter data\n");
        printf("2. Find the smallest element\n");
        printf("3. Find the largest element\n");
        printf("4. Search a node in the BST\n");
        printf("5. Deleting a node from the BST\n");
        printf("6. Inorder traversal\n");
        printf("7. Exit from the program\n");
        printf("\n");
        printf("Enter your option:");
        scanf("%d", &ch);
        switch(ch)
        {
        case 1:
            printf("Enter -1 to terminate\n");
            printf("Enter data item:");
            scanf("%d", &data);
            while (data != -1)
            {
                root = insert(root, data);
                printf("Enter the data item: ");
                scanf("%d", &data);
            }
            printf("Binary tree is created.\n");
            printf("\n");
            break;

        case 2:
            small = smallestbst(root);
            printf("Smallest element is:%d", small);
            printf("\n");
            break;

        case 3:
            large = largestbst(root);
            printf("Largest element is:%d", large);
            printf("\n");
            break;

        case 4:
            printf("which element you want to search: ");
            scanf("%d", &data);
            temp = searchanodebst(root, data);
            if (temp == NULL)
            {
                printf("data not found!!!\n");
            }
            else
                printf("data found.\n");
                printf("\n");
            break;

        case 5:
            printf("which element you want to delete: ");
            scanf("%d", &data);
            temp = deleteanodebst(root, data);
            if (temp == NULL)
            { 
                printf("Element does not found!!!\n");
            }
            else
                printf("Element deleted successfully\n");
            break;

        case 6:
                printf("In - order Traversal:");
                inorder(root);
                printf("\n");
                break;
        }
} while(ch<=6);

return 0;
}