#include <iostream>
#include <stack>
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


        //Zig Zag traversal
        //1. maintain 2 stacks - currentLevel & nextLevel and boolean variable leftToRight
        //2. if leftToRigth, push left child then right
        //3. else push right child then left

        void zigZagTraversal(Node* root){
            if(root==NULL){
                return;
            }

            //declare those 2 stacks and bool variable
            stack<Node*> currLevel;     
            stack<Node*> nextLevel;
            bool leftToRight = true;   //initially true


            //push root in the currLevel
            currLevel.push(root);        
            while(!currLevel.empty()){

                //save top node in temp and then work on it
                Node* temp = currLevel.top();  
                currLevel.pop();   //completely remove it from stack

                //now work on temp
                if(temp){
                    //print it 
                    cout<<temp->data<<" ";

                    if(leftToRight){
                        //first push insert left child
                        if(temp->left){
                            nextLevel.push(temp->left);
                        }

                        //then push right child

                        if(temp->right){
                            nextLevel.push(temp->right);
                        }
                    }
                         else{
                        //first push insert left child
                        if(temp->right){
                            nextLevel.push(temp->right);
                        }
                        //then push left child
                        if(temp->left){
                            nextLevel.push(temp->left);
                        }
                    }

                }

                if(currLevel.empty()){  //one level finished traversing, 
                //reverse the bool value
                leftToRight = !leftToRight;

                    //now nextLevel will be currLevel
                    swap(currLevel, nextLevel);
                }

            }
        }



        int main(){

            Node* root = new Node(12);

            root->left = new Node(9);
            root->right = new Node(15);

            root->left->left = new Node(5);
            root->right->right = new Node(10);


            //test
            zigZagTraversal(root);
            cout<<endl;
            return 0;
        }