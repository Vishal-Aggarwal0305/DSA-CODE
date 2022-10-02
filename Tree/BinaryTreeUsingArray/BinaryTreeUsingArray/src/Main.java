public class Main {
    public static void main(String[] args) {
        System.out.println("Hello world!");
        BinaryTree b = new BinaryTree(7);
        b.insert("h1");
        b.insert("h2");
        b.insert("h3");
        b.insert("h4");
        b.insert("h5");
        b.insert("h6");
        b.insert("h7");

        System.out.println();

        b.preOrder(1);
        System.out.println();
        b.postOrder(1);
        System.out.println();
        b.inOrder(1);
    }
}