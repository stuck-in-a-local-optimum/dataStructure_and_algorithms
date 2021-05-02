#include <iostream>

using namespace std;

//SHORTEST DISTANCE BETWEEN TWO NODES
//since shortest distance b/w 2 nodes must 
//go through their Lowest Common Ancestor (LCS)
//ALGO
//find the LCA of the nodes
//find d1 = distance of node1 from LCA and 
//find d2 = distance of node2 from LCA
//return d1+d2

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

        Node* findLCA(Node* root, int n1, int n2){

            //if root is null then return null
            if(root==NULL){
                return NULL;
            }

            //root is either of n1 or n2, then root will be LCA
            if(root->data == n1 || root->data ==n2){
                return root;
            }

            // check for left and right nodes
            Node* left = findLCA(root->left,  n1,  n2);
            Node* right = findLCA(root->right,  n1,  n2);

            //if both left and right are valid then root is the answer
            if(left!=NULL && right!=NULL){
                return root;
            }


            //if both left and right are invalid then return null
            if(left==NULL && right==NULL){
                return NULL;
            }

            //if exacltly one of them is not null then return that node
            if(left!=NULL){
                return findLCA(root->left,  n1,  n2);
            }
            return findLCA(root->right,  n1,  n2);

        }

        int findDist(Node* root, int n, int currDist){
            if(root==NULL){  //if no LCA is found
                return -1;   
            }

            if(root->data == n){ //at any level is root data is equal to node data then return currDistance
                return currDist; 
            }

            //if at any level, root.data not found to equal to node data 
            //then move to next level and increase currDist by 1
            int left = findDist(root->left, n, currDist+1);   
            if(left !=-1){
                return left;
            }
            return findDist(root->right, n, currDist+1);
        }

        int twoNodeDistance(Node* root, int n1, int n2){
            Node* lca = findLCA(root, n1, n2);

            int d1 = findDist(lca, n1, 0);
            int d2 = findDist(lca, n2, 0);

            return d1+d2;
        }





 

        


        int main(){

        struct Node* root = new Node(1);

        root->left = new Node(2);
         root->right = new Node(3);
         root->left->left = new Node(4);

            root->right->right = new Node(5);

        

        cout<<twoNodeDistance(root, 4, 5);





  
    return 0;
}