#include <iostream>
#include <queue>
using namespace std;


//right view of binary tree when we see the tree from right
//ALGO
//Traverse to each level and output its rightmost node

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


        void rightView(Node* root){
            if(root==NULL){
                return;
            }

            queue<Node*> q;
        

            q.push(root);
            // q.push(NULL);  //this time we will not push null to check level end
            //instead we calculate size if queue and traverse till last Node

            Node* levelRight = root->right;

            while(!q.empty()){
                int n = q.size();

                for(int i=0; i<n; i++){

                    Node* front = q.front();
                    q.pop();


                    if(i==n-1){   //to check level END!
                        cout<<front->data<<" ";
                    }

                    if(front->left!=NULL){
                        q.push(front->left);
                    }

                    if(front->right!=NULL){
                        q.push(front->right);
                    }

               
        }
                }
            }

        





int main(){

        struct Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

        root->left->left = new Node(4);
        root->left->right = new Node(5);
          root->right->left = new Node(6);
        root->right->right = new Node(7);

        rightView(root);




    return 0;
}