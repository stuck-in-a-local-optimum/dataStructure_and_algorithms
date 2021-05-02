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

        void printLevelOrder(Node* root){
        


            if(root==NULL){
                return;
            }

            queue<Node*> q;

            q.push(root);  //enqueue the root 
            q.push(NULL);
        

            while(!q.empty()){
                //print  first of queue and remove it from queue
                Node* front = q.front(); 
                 q.pop();     

                if(front!=NULL){
                cout<<front->data<<" "; //print the first node if not null
                    

                if(front->left!=NULL){   //if front have left child push it
                    q.push(front->left);
                }
                if(front->right!=NULL){   //if front have right child push it
                    q.push(front->right);
                }
                }
                else if(!q.empty()){  //if front is null but queue is not empty then one level complete so push null for next level
                    q.push(NULL);
                }
            }
        }


        int kLevelSum(Node* root, int k){
            int level=0;
            int ans=0;

            if(root==NULL){   //can't find the sum
                return -1;
            }

            queue<Node*> q;
            q.push(root);
            q.push(NULL);


            while(!q.empty()){
                

                Node* front = q.front();
             
                q.pop();

                if(front!=NULL){

                        if(level==k){
                       ans+=front->data;
                        }

                       if(front->left!=NULL){
                           q.push(front->left);
                       }
                       if(front->right!=NULL){
                           q.push(front->right);
                       }

                }
                else if(!q.empty()){
                    level++;
                    q.push(NULL);
                   
                }
            
                
                

            }
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
        printLevelOrder(root);

        cout<<endl;

        cout<<kLevelSum(root, 2);


        cout<<endl;

        cout<<kLevelSum(root, 0);



    return 0;
}