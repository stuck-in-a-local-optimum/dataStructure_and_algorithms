#include <iostream>
using namespace std;


struct Node{
    int data;
    Node* next;
    Node* prev;

    Node(int val){
        data = val;
        next = NULL;
        prev  = NULL;
    }
};


void insertAtHead(Node* &head, int val){
    Node* node = new Node(val);

    node->next = head;
    if(head!=NULL){
    head->prev = node;
    }

    head = node;

}

void insertAtTail(Node* &head, int val){

    if(head==NULL){

        insertAtHead(head, val);
        return ;

    }

    Node* node = new Node(val);
    Node* temp = head;


    while(temp->next!=NULL){
        temp = temp->next;
    
    }

    temp->next = node;
    node->prev = temp;


     
}


void display(Node* head){
    Node* temp = head;

    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;

    }
    cout<<endl;
}

void deleteAtHead(Node* &head){
    Node* toDelete = head;

    head = head->next;
    head->prev = NULL;

    delete toDelete;
}

void deletion(Node* &head, int pos){
    if(pos==1){
        deleteAtHead(head);
    }
    Node* temp = head;
    int count=1;

    while(temp!=NULL && count<pos){
        temp = temp->next;
        count++;
    }

    temp->prev->next = temp->next;
    if(temp->next!=NULL){
    temp->next->prev = temp->prev;
    }

    delete temp;

}




int main(){
    Node* head = NULL;

    insertAtTail(head , 1);
        insertAtTail(head , 2);

    insertAtTail(head , 3);

    insertAtTail(head , 4);


    display(head);
    insertAtHead(head, 5);

    display(head);

    deletion(head, 5);
    display(head);




    return 0;
}