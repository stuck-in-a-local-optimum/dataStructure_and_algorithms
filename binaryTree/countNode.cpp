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

        int countNodes(Node* root){
            if(root==NULL){
                return 0;
            }

            return countNodes(root->left)+ countNodes(root->right)+1;
        }

        int nodesSum(Node* root){
            if(root==NULL){
                return 0;
            }

            return nodesSum(root->left)+nodesSum(root->right)+root->data;
        }


int main(){

        struct Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

        root->left->left = new Node(4);
        root->left->right = new Node(5);
          root->right->left = new Node(6);
        root->right->right = new Node(7);

        cout<<countNodes(root)<<endl;
        cout<<endl;
        cout<<nodesSum(root);



    return 0;
}