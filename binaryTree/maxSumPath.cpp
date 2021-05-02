#include <iostream>
#include <queue>
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



        //FIND MAXIMUM POSSIBLE SUM OF A PATH IN THE BT
        //ALGO
        //for each node, compute:
        //1. Node value
        //2. Max path through left child + node value
        //3. Max path through right child+ node value
        //4. Max path through left child + Max path through right child + node value


         int maxPathSumUtil(Node* root, int &ans){
            if(root==NULL){
                return 0;  //if no path exist then sum is 0
            }

            int left = maxPathSumUtil(root->left, ans);
            int right = maxPathSumUtil(root->right, ans);

            int nodeMax = max ( max(root->data, root->data + left + right), 
                    max( root->data + left, root->data+ right));
            
            ans = max( ans, nodeMax);
            int singlePathSum = max(root->data, max(root->data + left, root->data+right))  ;

            return singlePathSum;




        }

        int maxPathSum(Node *root){
            int ans = INT_MIN; 
            maxPathSumUtil(root, ans);
            

            return ans;

        }

       





        int main(){

            struct Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

        root->left->left = new Node(4);
        root->left->right = new Node(5);
          root->right->left = new Node(6);
        root->right->right = new Node(7);

        cout<<maxPathSum(root)<<endl;;


            return 0;
        }


