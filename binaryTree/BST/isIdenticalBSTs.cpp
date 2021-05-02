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
        For given root nodes of 2 binary search tree, print if
        the BSTs are identical or not.
        Identical BSTs are structurily identical & have equal
        values for the nodes in the structure.
        */

       //STRATEGY
       //if both empty, return true
       //if both root nodes not empty:
            //a check that the data at root nodes is equal
            //b check if left subtrees are same
            //c check if right subtrees are same
        //if (a,b, c) are true then return true


        bool isIdentical(Node* root1, Node* root2){
            if(root1==NULL && root2==NULL){
                return true;
            }

            if(root1==NULL || root2==NULL){
                return false;
            }

            if(root1!=NULL && root2!=NULL){

                if(root1->data==root2->data){
                    bool leftTrue = isIdentical(root1->left, root2->left);
                    bool rightTrue=isIdentical(root1->right, root2->right);
                    
                    return leftTrue && rightTrue;
                }
                

            }
            return false;
            
        }



int main(){

    Node* root = new Node(2);

    root->left = new Node(1);
    root->right = new Node(3);

    if(isIdentical(root, root)){
        cout<<"identical BSTs"<<endl;
    }
    else{
        cout<<"not identical!"<<endl;
    }





    return 0;
}