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

        Node* insertInBST(Node* root, int val){

            if(root==NULL){
                return new Node(val);
            }

            if(val< root->data){
                root->left = insertInBST(root->left, val);
                
            }
            else{
                root->right = insertInBST(root->right, val);
            }


            return root;

        }

        void inOrder(Node* root){
            if(root==NULL){
                return;
            }


            inOrder(root->left);
            cout<<root->data<<" ";
            inOrder(root->right);
        }


        //IN BINARY TREE, SEARCH COMPLEXITY IS O(N) 'CAUSE WE NEED TO LOOK TO EACH NODE
        //BUT IN BST, IT IS O(logn) because we knw left and right tree contains smaller and greater node for each node
        //only one comparision at each level, so O(n)

        Node* searchInBST(Node* root, int key){

            if(root==NULL){
                return NULL;
            }


            if(root->data==key){
                return root;
            }

               //data > key
            if(root->data > key){
                return searchInBST(root->left, key);
            }

            //data < key

            return searchInBST(root->right, key);
        }

                //DELETE IN BST
        //There will be three cases when toBeDeleted node either have
        //no children, or 1 children or two children
        //if no children then simply delete that node
        //if  single children then  replace given node with its single child
        //if node have two children, then find the inOrderSuccesor (value afer gigven)
        //replace the node with inOrder succecssor and then delete the node
        //since inOrder traversal of BST gives sorted order so inOrder successor will be next number,i.e if key is 3 then its inOrdere succesor is 4


        Node* inOrderSucc(Node* root){
            Node* curr = root;

            while(curr && curr->left !=NULL){
                curr = curr->left;
            }
            return curr;


        }

       //This func deletes the key node and returns new node
        Node* deleteInBST(Node* root, int key){


            //key lies in left subtree then call delete for lefttree and update root's left subtree with new node
            if(key < root->data){
                root->left = deleteInBST(root->left, key);
            }

            //key lies in right subtree then call delete for righttree and update root's right subtree with new node
             else if(key > root->data){
                root->right = deleteInBST(root->right, key);
            }


            //if root is the node to be deleted then we have 3 cases
            //i)root has no child ii)root has only one child(left/right)  iii) root has both children
            else {
            //for case i) & ii) both done by following code
            if(root->left==NULL){
                Node* temp = root->right;  //store the right subtree of node
                free(root);
                return temp; //new node will be temp

            }
            else if(root->right==NULL){
                Node* temp = root->left;
                free(root);
                return temp;

            }

            //case 3    root has both children
            Node* temp = inOrderSucc(root->left);  //in BST, it will always come from rightSubtreee

            root->data  = temp->data;   //change the root data to inOrderSucc's data
            root->right = deleteInBST(root->right, temp->data);  //delete the inOrderSucc from rightSubtree and return new node 
            }

            return root;

        }

      





        int main(){


            Node* root = NULL;

            root = insertInBST(root, 5);

            insertInBST(root, 1);
            insertInBST(root, 3);
            insertInBST(root, 4);
            insertInBST(root, 2);
            insertInBST(root, 7);

            inOrder(root);  //INORDER TRAVERSAL OF A BINARY SEARCH TREE GIVES SORTED ORDER!!

            cout<<endl;

            if(searchInBST(root, 35)){
                cout<<"key exists"<<endl;
            }
            else {
                cout<<"key does not exists"<<endl;
            }

               cout<<endl;

                cout<<"Inorder before deletion"<<endl;

                  inOrder(root);

               root = deleteInBST(root, 3);
               cout<<"Inorder after deletion"<<endl;
               inOrder(root);
            return 0;
        }

     


