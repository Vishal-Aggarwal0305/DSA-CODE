public class BinaryTree {
    String[] arr;
    int lastUsedIndex;

    BinaryTree(int size)
    {
        arr = new String[size+1];
        this.lastUsedIndex = 0;
        System.out.println("Binary Tree created");
    }

    boolean isFull()
    {
        if(arr.length-1 == this.lastUsedIndex)
        {
            return true;
        }
        else {
            return false;
        }
    }

    //insert Element
    void insert(String value)
    {
        if(!isFull())
        {
            arr[lastUsedIndex+1] = value;
            lastUsedIndex++;
            System.out.println("the value "+value +"have been inserted");
        }
        else
        {
            System.out.println("tree is full");
        }
    }

    //preorder traversal
    void preOrder(int idx)
    {
        if(idx>lastUsedIndex)
        {
            return;
        }

        System.out.print(arr[idx] + "   ");
        preOrder(idx * 2);
        preOrder(idx*2+1);
    }

    //inorder traversal
    void inOrder(int idx)
    {
        if(idx>lastUsedIndex)
        {
            return;
        }

        postOrder(idx * 2);
        System.out.print(arr[idx] + "   ");
        postOrder(idx*2+1);
    }

    //preorder traversal
    void postOrder(int idx)
    {
        if(idx>lastUsedIndex)
        {
            return;
        }

        postOrder(idx * 2);
        postOrder(idx*2+1);
        System.out.print(arr[idx] + "   ");
    }
}
