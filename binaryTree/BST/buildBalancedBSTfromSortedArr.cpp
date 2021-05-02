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



        //STRATEGY   (binary search approach)
        // make middle element the root
        //recursively, do the same for subreess
                //a start to mid-1 for left subtree
                //b mid+1 to end for the right subtree


        //the tree by this approach will be the balanced one


        Node* buildBalancedBST(int sortedArr[], int start, int end){

                if(start>end){
                    return NULL;
                }
            int mid = (start+ end)/2;

            Node* root = new Node(sortedArr[mid]);

            root->left = buildBalancedBST(sortedArr, start, mid-1);
            root->right = buildBalancedBST(sortedArr, mid+1, end);


            return root;
        }


        void printPreOrder(Node* root){
            if(root==NULL){
                return ;
            }

            cout<<root->data<<" ";
            printPreOrder(root->left);
            printPreOrder(root->right);


        }




        int main(){


            int arr[]  = {10, 20 , 30, 40, 50};

            Node* root = buildBalancedBST(arr, 0, 4);

            printPreOrder(root);




            return 0;
        }