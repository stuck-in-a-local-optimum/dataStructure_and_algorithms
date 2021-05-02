#include <iostream>
#include <climits>

using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;


    Node(int val){
        data = val;
     left= NULL;
     right = NULL;
}
};



//2 NODES OF A BST ARE SWAPPED. OUR TASK IS TO RESTORE(CORRECT) THE BST

//STRATEGY
//since inorder of a BST is sorted
//so our problem reduce to restore our inORder sequence
//2 elements in a sorted array are swapped and needs to bring back to their 
//correct position 



//we will maintain three pointers in each case, first, mid and last
//first -> previous node where first time a no. < previous
//mid -> no. where first time a  no. < previous
//last -> 2nd node where no. < previous 
//case1: swapped elements are not adjacent to each other
//e.g inOrder ={1, 8, 3, 4, 5, 6, 7, 2}
//first = 8
//mid = 3
//last =2

//sol.-> swap(first, last)

//case2: swappd elements are adjacent to each other 
//e.g = {1, 2, 4, 3, 5, 6, 7, 8}
//first = 4
//mid = 3
//last = null

//sol.-> swap(first, mid)


void calcPointers(Node* root, Node** first, Node** mid, Node** last, Node** prev){
    if(root==NULL){
        return;
    }


    //we will to do calculation alike inOrder sense (left-->root-->right)

    calcPointers(root->left, first, mid, last, prev);

    //now we do some calculations
    //if rule breaks
    if( *prev && root->data < (*prev)->data){
        //rule broke at first time i.e if first is null till now
        if(!*first){
            *first = *prev;
            *mid = root;
        }
        else{
            *last = root;
        }


    }

            *prev = root;  //update the temp node 
        
        calcPointers(root->right, first, mid, last , prev);


}


void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;

}

void inOrder(Node* root){
    if(root==NULL){
        return;
    }

    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}



void restoreBST(Node* root){
   

    //Maintain three pointers
    Node* first=NULL;
    Node* mid=NULL;
    Node* last=NULL;
    Node* prev=NULL;  //act a  temp node

    //calculate the above pointers
    calcPointers(root , &first, &mid, &last, &prev);

    //case1
    if(first && last){
        swap(&(first->data), &(last->data));
    }
    //case2
    else if(first && mid){
        swap( &(first->data), &(mid->data));
    }



}




int main(){

    /*
             6
            / \
           9   3
          / \    \
         1    4   13

    */

   Node *root = new Node(6);
   root->left = new Node(9);
   root->right = new Node(3);
   root->left->left = new Node(1);
   root->left->right = new Node(4);
   root->right->right = new Node(13);

    inOrder(root);
    cout<<endl;


    restoreBST(root);

    inOrder(root);


    return 0;
}