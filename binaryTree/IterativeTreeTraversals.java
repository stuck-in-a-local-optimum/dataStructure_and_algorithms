package binarytree;

import java.util.*;

class Node{
    int data;
    Node left;
    Node right;
    public Node(int data){
        this.data = data;
        this.left = null;
        this.right = null;
    }

}


class IterativeTreeTraversals{

    public static void main(String[] args){

        Node root = new Node(10);
        root.left = new Node(8);
        root.right = new Node(2);
        root.left.left = new Node(3);
        root.left.right = new Node(5);
        root.right.left = new Node(2);

        IterativeTreeTraversals.iterativePreOrder(root);
        System.out.println();
        System.out.println();


        IterativeTreeTraversals.iterativeInOrder(root);
        System.out.println();

        System.out.println();


        IterativeTreeTraversals.iterativePostOrder(root);
        System.out.println();

        IterativeTreeTraversals.levelOrder(root);



    }


    public static void iterativePreOrder(Node root){  
        //------ALGO----
        /*
        1) Push the root node in stack
        2) pop and store top of node from stack
        3) print the popped node
        4) push right node 
        5) push left node
        
        */

        if(root==null){
            return;
        }

        Stack<Node> myStack = new Stack<Node>();

        myStack.push(root);

        while(!myStack.empty()){
            Node curr = myStack.pop();

            System.out.print(curr.data+" ");
            if(curr.right!=null){
                myStack.push(curr.right);}
           
                if(curr.left!=null){
                    myStack.push(curr.left);}

        }

    }

    public static void iterativePostOrder(Node root){
        /*----ALGO------
        We will using two stacks
        1. Push the root ot 1st stack
        2. Pop top node from s1 and push it to s2
        3. push (popped node->left , popped node ->right in s1 if they exists)

        4. Print contents of s2 by popping till it empty
        
        */

        if(root==null){
            return;
        }

        Stack<Node> s1 = new Stack();
        Stack<Node> s2 = new Stack();

        s1.push(root);

        while(!s1.empty()){
            Node curr = s1.pop();

            s2.push(curr);

            if(curr.left!=null){
                s1.push(curr.left);

            }
            if(curr.right!=null){
                s1.push(curr.right);

            }
        }


        //Print all the elements of the s2, it will be postOrder
        while(!s2.empty()){
            System.out.print(s2.pop().data+" ");
        }

    }


public static void iterativeInOrder(Node root){

    /*------ALGO-----
    1) initialize curr node to root
    2) push curr ndoe to stack and update curr = curr.left till we reach leftmost node i.e curr becomes null
    3) if curr is null && stack is not empty yet
        then i) pop the top of stack and print it
             ii) set curr = popped node -> right
            iii) repeat step3
        else
            if(curr==null && stack is empty) then we are done.


     */
    if(root==null){
        return ;
    }

    Stack<Node> myStack = new Stack();
    Node curr = root;
    

    while( curr!=null || !myStack.empty() ){

        //reach the leftmost of the curr node and keep pushing the nodes
        while(curr!=null){
        myStack.push(curr);
        curr = curr.left;
        }

    


    //so far we have reached to leftmost node of curr and curr now is null
    //so print and pop the top of the stack
    curr = myStack.pop();
    System.out.print(curr.data+" ");

    //we are done with the leftsubtree, now its's right subtree's turn
    curr = curr.right;

}
}


    public static void levelOrder(Node root){
        if(root==null){
            return ;
        }

        Queue<Node> q = new LinkedList<>();

        q.add(root);

        while(!q.isEmpty()){
            Node front = q.remove();
            System.out.print(front.data+" ");

            if(front.left!=null){
                q.add((front.left));
            }
            if(front.right!=null){
                q.add((front.right));
            }
        }
    }


}