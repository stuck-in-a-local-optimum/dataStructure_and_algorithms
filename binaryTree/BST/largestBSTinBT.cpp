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


//RETURN THE SIZE OF THE LARGEST BST IN A
//BINARY TREE


//STRATEGY
//WE WILL TRAVERSE IN BOTTUM-UP MANNER
//for each node store the following info:
//1 min in subtree of that node
//2 max in subtree of that node
//3 subtree size
//4 size of largest BST, if exists
//5 isBST


struct Info{

    int min;
    int max;
    int size;
    int ans;
    bool isBST;
};

Info largestBSTinBT(Node* root){

    if(root==NULL){
        return {INT_MAX, INT_MIN, 0, 0, true};
    }

    if(root->left==NULL && root->right==NULL){   //leaf node
            return {root->data, root->data, 1, 1, true};

    }


    //TRAVERSING IN BOTTUM-UP MANNER
    Info leftInfo = largestBSTinBT(root->left);
    Info rightInfo = largestBSTinBT(root->right);

    Info currInfo;
    currInfo.size = (1+leftInfo.size + rightInfo.size);   //other info will depend it is BST or not


    //check curr node is BST or not
    if(leftInfo.isBST && rightInfo.isBST && (leftInfo.max < root->data && root->data < rightInfo.min)){  //if it is a BST
            currInfo.min = min( leftInfo.min, min(rightInfo.min, root->data));
            currInfo.max = max(rightInfo.max, max(leftInfo.max, root->data));
            currInfo.ans = currInfo.size;
            currInfo.isBST = true;
            return currInfo;

    }
    //else if not BST
    currInfo.ans = max(leftInfo.ans, rightInfo.ans); //largest BST from substrees
    currInfo.isBST = false;


    return currInfo; 

}




int main(){


    Node* root = new Node(15);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(5);



    cout<< "Largest BST in BT have size : " <<largestBSTinBT(root).ans<<endl;



    return 0;
}