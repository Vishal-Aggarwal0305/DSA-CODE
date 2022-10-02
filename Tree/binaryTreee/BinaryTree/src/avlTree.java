import java.util.*;

public class avlTree {
    avlNode root = new avlNode();

    avlTree()
    {
        root = null;
    }

    void inoredr()
    {
        Queue<avlNode> que = new LinkedList<>();
        que.add(root);
        while (!que.isEmpty())
        {
            avlNode node = que.poll();
            System.out.println(node.value + "   ");
            if(node.left!=null)
            {
                que.add(node.left);
            }
            if(node.right!=null)
            {
                que.add(node.right);
            }
        }
    }

    int getHeight(avlNode node)
    {
        if(node == null)
        {
            return 0;
        }
        return node.height;
    }

    int balance(avlNode node)
    {
        if(node == null)
        {
            return 0;
        }

        return getHeight(node.left) - getHeight(node.right);
    }

    void rightRotate(avlNode node)
    {
        avlNode newRoot = node.left;
        node.left = node.left.right;
        newRoot.right = node;

    }


}
