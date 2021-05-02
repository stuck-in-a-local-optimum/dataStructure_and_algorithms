#include <iostream>
using namespace std;

struct Node
        {
            int data;
            struct  Node* left;
            struct Node* right;

            Node(int val)
            {
                data = val;
                left = NULL;
                right = NULL;
            };
            
        };

/*Given a binary tree, flatten it into
linked list in-place. After flattening, left 
of each node should point null and right should 
contain next node in preOrder sequence
(It's not allowed to use other data structure)
*/

//ALGO
//1 Recursively, flatten the left & right subtrees
//2 store the left & right tail (tail is last node of subtree)
//3 store right subtree in 'temp' & make left subtree as right subtree
//4 join right subtree with left tail
//5 return right tail 



void flatten(Node* root){
    if(root==NULL || (root->left==NULL && root->right==NULL)){  //in these cases, treee is already sorted
        return;
    }

    if(root->left!=NULL){
        flatten(root->left);   //first flatten left subtree

        Node* temp= root->right;  //store root's right 
        root->right = root->left;  //this left has been flattened so add as right subtree
        root->left = NULL;   //make left substree NULL

        Node* t = root->right;   //this right is above flattened left subtree


        while(t->right!=NULL){    //find the tail
            t = t->right;
        }
         t->right = temp;   //point tail to right subtree
}
        flatten(root->right);  //now flatten right subtree

}


void inOrderPrint(Node* root){
    if(root==NULL){
        return;
    }

    inOrderPrint(root->left);
    cout<<root->data<<" ";
    inOrderPrint(root->right);

}





int main(){

    Node* root = new Node(4);
    root->left = new Node(9);

    root->right = new Node(5);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->right = new Node(6);

    flatten(root);
    inOrderPrint(root);




    return 0;
}

