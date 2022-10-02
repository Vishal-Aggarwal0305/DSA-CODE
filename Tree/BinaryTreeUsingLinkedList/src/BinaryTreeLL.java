import java.util.LinkedList;
import java.util.Queue;

public class BinaryTreeLL {
    BinaryNode root;

    BinaryTreeLL()
    {
        this.root = null;
    }

    //preorder traversal
    void preorder(BinaryNode node)
    {
        if(node == null)
            return;

        System.out.print(node.data + "  ");
        preorder(node.left);
        preorder(node.right);
    }

    //inorder
    void inorder(BinaryNode node)
    {
        if(node == null)
            return;

        inorder(node.left);
        System.out.print(node.data + "  ");
        inorder(node.right);
    }

    //postorder
    void postorder(BinaryNode node)
    {
        if(node == null)
            return;

        postorder(node.left);
        postorder(node.right);
        System.out.print(node.data + "  ");
    }

    //levelOrder Traversal
    void levelOrder()
    {
        Queue<BinaryNode> q = new LinkedList<>();
        q.add(root);
        while(!q.isEmpty())
        {
            BinaryNode temp = q.remove();
            System.out.print(temp.data + " ");
            if(temp.left!=null)
            {
                q.add(temp.left);
            }
            if(temp.right!=null)
            {
                q.add(temp.right);
            }
        }
    }

    //search
    void search(String value)
    {
        Queue<BinaryNode> q = new LinkedList<>();
        q.add(root);
        while(!q.isEmpty())
        {
            BinaryNode temp = q.remove();
            if(temp.data == value)
            {
                System.out.println("value " + value +" is found");
                return;
            }
            if(temp.left!=null)
            {
                q.add(temp.left);
            }
            if(temp.right!=null)
            {
                q.add(temp.right);
            }
        }
        System.out.println("Value" + value + "is not found");
    }

    //insert element
    void insert(String data)
    {
        BinaryNode newNode = new BinaryNode();
        newNode.data = data;
        if(root == null)
        {
            root = newNode;
            return;
        }
        Queue<BinaryNode> q = new LinkedList<>();
        q.add(root);
        while(!q.isEmpty())
        {
            BinaryNode temp = q.remove();
            if(temp.left == null)
            {
                temp.left = newNode;
                return;
            }
            if(temp.right == null)
            {
                temp.right = newNode;
                return;
            }
            q.add(temp.left);
            q.add(temp.right);
        }

    }
}
