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



/*
BALANCED HEIGHT TREE
For each node, the  absolute difference b/w the height of the 
left subtree & right subtree <=1 
*/

int treeHeight(Node* root){
    if(root==NULL){
        return 0;
    }

    return max( treeHeight(root->left), treeHeight(root->right) )+1;
}


//following have time complexity O(n^2)
//we are calling the func for each node and 
//for each node we are also calling treeHeight() which also takes O(n)
//so overall complexity O(n^2)
// we can do better (int O(n)) by keeping pointers for height instead of calling treeheight()
bool isBalancedTree(Node* root){

    //empty node always balanced
    if(root==NULL){
        return true;
    }

    //if left subtree is not balanced then tree not balanced, return false
    if(isBalancedTree(root->left)==false){
        return false;
    }

    //if right subtree is not balanced then tree not balanced, return false
    if(isBalancedTree(root->right)==false){
        return false;
    }

    //if both subtree balanced then calculate their height and check 
    //for root node
    int lH = treeHeight(root->left);
    int rH = treeHeight(root->right);

    if(abs(lH-rH)<=1){
        return true;
    }
    return false;

}


bool optimisedIsBalancedTree(Node *root, int *height){
    //heigt pointer is the height of current root

    //base case
    if(root==NULL){
        return true;
    }

    int lH=0; int rH=0;

    if(optimisedIsBalancedTree(root->left, &lH)==false){
        return false;
    }

      if(optimisedIsBalancedTree(root->right, &rH)==false){
        return false;
    }

    //update the height of tree 
    *height = max(lH, rH)+1;

    if(abs(lH-rH)<=1){
        return true;
    }
    return false;

}





int main(){

    struct Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

        root->left->left = new Node(4);
        root->left->right = new Node(5);
          root->right->left = new Node(6);
        root->right->right = new Node(7);

        if(isBalancedTree(root)){
            cout<<"BALANCED TREE"<<endl;
        }
        else{
            cout<<"UNBALANCED TREE"<<endl;
        }


        //OPTIMISED BALANCED TREE FUNCTION
        int height = 0;

        if(optimisedIsBalancedTree(root, &height)){
            cout<<"BALANCED TREE"<<endl;
        }
        else{
            cout<<"UNBALANCED TREE"<<endl;

        }

        


    return 0;
}