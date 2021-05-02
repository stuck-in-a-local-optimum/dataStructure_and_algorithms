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


        //PRINT ALL THE NODES WHICH ARE AT 'K' DISTANCE
        //AWAY (BELOW OR ABOVE) TO THAT NODE

        //There will be two cases:
        /*i) finding req. nodes in subtree of target node

            in this case we will call our func for each node in the
            subtree and will decrease the value of k by 1 at each call
             and when k=0, add this node to ans

          ii) finding the req. nodes in the Ancestor of the target node
                a)  find the distance (say d) of all ancestors from target node
                b) for each ancestor search other subtree nodes which are at (k-d) distance 
                   we will do this in following way that
                   if target nodes is in left subtre of Ancestor then search in right subtree of ancestor
                   and otherwise search in left subtree

        */

       //case1, search in subtrees
       int printSubtreeNodes(Node* root, int k){
           if(root==NULL || k<0){
               return;
           }

           if(k==0){
               cout<<root->data<<" ";
           }

           printSubtreeNodes(root->left, k-1);
           printSubtreeNodes(root->right, k-1);
       }

       //case2, search in ancestor
       int printNodesAtK(Node *root, *target, int k){
           
       }




        






int main(){




    return 0;
}