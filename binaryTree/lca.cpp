#include <iostream>
#include <vector>
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

        bool getPath(Node* root, int key, vector<int> &path){
            if(root==NULL){
                return false;
            }

            //assuming initially our path is correct so push this root in path vector
            path.push_back(root->data);  

            if(root->data==key){
                        return true;      //path found
            }

                //return true key is in either subtree
            if(getPath(root->left, key, path) || getPath(root->right, key, path)){
                return true;

            }


            //otherwise path no found 
            path.pop_back();
            return false;




        }

        int lca(Node* root, int n1, int n2){    //O(n)

            vector<int> path1, path2;

            if(!getPath(root, n1, path1) || !getPath(root, n2, path2)) {
                return -1;  //lca not possible
            }

            int pointOfchange;

            for(pointOfchange=0; pointOfchange< path1.size() && path2.size(); pointOfchange++){
                if(path1[pointOfchange] != path2[pointOfchange]){   //if different node in the path found then its the lca
                    break;

                }

            }
            return pointOfchange;


        }


    int main(){

               Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

        root->left->left = new Node(4);
        root->left->right = new Node(5);
          root->right->left = new Node(6);
        root->right->right = new Node(7);


        int n1=6;
        int n2 = 7;

        int LCA = lca(root, n1, n2);
        if(LCA==-1){
            cout<<"LCA doesn't exist"<<endl;
        }
        else{
            cout<<"LCA : "<<LCA<<endl;
        }



        return 0;
    }