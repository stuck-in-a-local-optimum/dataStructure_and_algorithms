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


        //FUNCTION TO REPLACE VALUE OF EACH NODE TO SUM OF VALUES OF ITS BOTH SUBTREE + NODE VALUE


    void sumReplace(Node* root){

        if(root==NULL){
            return;
        }

        //first call for left and rigth subtree
        sumReplace(root->left);
        sumReplace(root->right);

        //if subtrees are not null then add their data to root
        if(root->left!=NULL){
            root->data+= root->left->data;
        }

          if(root->right!=NULL){
            root->data+= root->right->data;
        }  

    }

    void preOrder(Node* root){
        if(root==NULL){
            return;
        }

        cout<<root->data<<" ";
        preOrder(root->left);
        preOrder(root->right);
    }



int main(){

    struct Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

        root->left->left = new Node(4);
        root->left->right = new Node(5);
          root->right->left = new Node(6);
        root->right->right = new Node(7);

        preOrder(root);
        cout<<endl;

        sumReplace(root);
        cout<<endl;

        preOrder(root);



    return 0;
}