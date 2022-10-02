import java.util.*;

public class Main {
    public static void main(String[] args)
    {
        BinaryTreeLL b = new BinaryTreeLL();
//        BinaryNode h1 = new BinaryNode();
//        h1.data = "h1";
//        BinaryNode h2 = new BinaryNode();
//        h2.data = "h2";
//        BinaryNode h3 = new BinaryNode();
//        h3.data = "h3";
//        BinaryNode h4 = new BinaryNode();
//        h4.data = "h4";
//        BinaryNode h5 = new BinaryNode();
//        h5.data = "h5";
//
//        h1.left = h2;
//        h1.right = h3;
//        h2.left = h4;
//        h2.right = h5;
//
//        b.root = h1;
//        b.preorder(b.root);
//        System.out.println();
//        b.inorder(b.root);
//        System.out.println();
//        b.postorder(b.root);
//        System.out.println();
//        b.levelOrder();
//        System.out.println();
//        b.search("h4");

        b.insert("h1");
        b.insert("h2");
        b.insert("h3");
        b.insert("h4");
        b.insert("h5");
        b.insert("h6");
        b.insert("h7");
        b.insert("h8");
        b.insert("h9");

        b.levelOrder();
        System.out.println();
        b.preorder(b.root);
        System.out.println();
        b.inorder(b.root);
        System.out.println();
        b.postorder(b.root);
    }


}