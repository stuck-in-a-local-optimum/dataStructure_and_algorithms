#include <iostream>
using namespace std;

        /*
            For each Node in preOrder sequence, we will maintain a pair of
            (min, max) condition for that node, if the next node to be inserted satisfied
            that condition then we will add this new nod to appropriate subtree of that node
        */


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

        Node* constructBST( int preOrder[], int* preOrderIdx, int key, int min, int max, int n){

                if( *preOrderIdx>=n){
                    return NULL;
                } 


            Node* root = NULL;    //declare root node
            if( key>min && key<max){
                root = new Node(key);    //if key satisifes then add it to the tree

                *preOrderIdx = *preOrderIdx+1;   //increment to reach next node to insert

                if(*preOrderIdx<n){   //this still nodes left to be inserted

                    //buil left subtree
                    root->left = constructBST(preOrder, preOrderIdx, preOrder[*preOrderIdx], min, key, n );

                }

                if(*preOrderIdx<n){
                    root->right = constructBST( preOrder, preOrderIdx, preOrder[*preOrderIdx], key, max, n);
                }

            }
            return root;
        }

        void printPreOrder(Node* root){
            if(root==NULL){
                return;
            }

            cout<<root->data<<" ";
            printPreOrder(root->left);
            printPreOrder(root->right);

        }


        int main(){


            Node* root = NULL;
            int preOrder[] = {10, 2, 1, 13, 11};

            int n = 5;

            int preOrderIdx = 0;

            root = constructBST( preOrder, &preOrderIdx, preOrder[0], INT_MIN, INT_MAX, n );
            printPreOrder(root);
            
            return 0;
        }


      
