#include <iostream>
#include <map>
#include <vector>
#include <iterator>
using namespace std;

        /*----------- PRINT VERTICAL ORDER OF BINARY TREE------
        STRATEGY: Computing horizontal distance approach

            1) hDistance of a node is the distance taking root node as origin
            2) storing as key value pair in a map <hDistance, Node that have that hDistance from root node> myMap
            3) call for left subtree and decrement the hDistance by -1
            4) call for right subtree and increment the hDistance by +1

        */



struct Node
{
    int data;
    Node *left, *right;

    Node(int d){
        data = d;
    }
};

void getVerticalOrder(Node* root, int hDistance, map<int, vector<int> > &myMap){

    if(root==NULL){
        return;
    }
    
    myMap[hDistance].push_back(root->data);
    getVerticalOrder(root->left, hDistance-1, myMap);
    getVerticalOrder(root->right, hDistance+1, myMap);

}






int main(){
    Node* root = new Node(10) ;
    root->left = new Node(7);
    root->right = new Node(4);
    root->left->left = new Node(3);
    root->left->right = new Node(11);
    root->right->left = new Node(14);
    root->right->right = new Node(6);

    map<int , vector<int> > myMap;
    int hDistance = 0;   //0 from root node i.e from 10

    getVerticalOrder(root, hDistance, myMap);

    map<int ,vector<int> > :: iterator it;
    
    for(it = myMap.begin(); it!=myMap.end(); it++){
        for(int i=0; i< (it->second).size(); i++){

            cout<<(it->second)[i]<<" ";


        }

        cout<<endl;
    }




    return 0;
}