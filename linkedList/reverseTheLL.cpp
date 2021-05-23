#include <iostream>
using namespace std;


struct Node{
    public:
     int data;
     Node* next;

     Node(int val){
         data  = val;
         next = NULL;
}
}*head;

void display(Node* head){
    Node* temp = head;

    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<endl;

}


//recursive approach
void reverseLinkedList(Node* prev, Node* curr){
    if(curr==NULL){
        return;  //if linkedlist is empty
    }

    if(curr->next==NULL){  //if curr is the last node of the LL
            head = curr;  //make it head of the LL
            curr->next = prev;
            return;
    }


        //otherwise
    reverseLinkedList(NULL, curr->next);
    curr->next = prev;  //reverse each node after each call
}


//iterative approach
void reverseLinkedList2(Node* head){

    //we will maintain three pointers
    Node* prev = NULL;
    Node* curr = head;
    Node* save;

    while(curr){  //work till last node
    save = curr->next;
    curr->next = prev;
    prev = curr;
    curr = save;

    }

    head = prev;

    cout<<"reversed linked list:\n";
    display(head);
}




int main(){
    head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = NULL;

    reverseLinkedList2(head);



    return 0;
}

