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



        //APPROACH
        // for a node, find Max of left subtree (maxL)
        // min of right subtree (minR)
        //if   maxL<node<minR then node is valid at its position
        //a small optimization we can make is to maintain a part of (min, max) 
        //for a given node and check if the node satisfies the condition



        //check for BST

        bool isBST( Node* root, Node* min=NULL, Node* max=NULL){
                if(root==NULL){
                    return true;
                }

            if(min!=NULL && root->data <= min->data){
                return false;   //root data must greater than min data
            }

            if(max!=NULL && root->data >= max->data){
                return false;   //root data must greater than min data
            }

            bool isLeftValid = isBST(root->left, min, root);
            bool isRightValid = isBST(root->right, root, max);

            return isLeftValid && isRightValid;
        }



        int main(){

            Node* root = new Node(1);
            
            root->left = new Node(2);
            root->right = new Node(3);


                if(isBST(root, NULL, NULL)){
                    cout<<"Valid BST"<<" "; 
                }
                else{
                    cout<<"NOT A VALID BST"<<" ";
                }



            return 0;
        }