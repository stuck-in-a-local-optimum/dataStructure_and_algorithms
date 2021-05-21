#include <iostream>
using namespace std;

class Node{
    public:
     int data;
     Node* next;

     Node(int val){
         data  = val;
         next = NULL;
}
};


void insertLast(Node* &head, int value){
    Node* node = new Node(value);

    if(head==NULL){
        head =node;
        return ;
    }

    Node* temp =head;

    while (temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=node;

}

void insertAtHead(Node* head,int  val){
    Node* node = new Node(val);
    node->next = head;
    head = node;
}

void display(Node* head){
    Node* temp = head;

    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<endl;

}


bool search(Node* head, int val){
    Node* temp = new Node(val);

    while (temp->next!=NULL)
    {
        if(temp->data==val){
            return true;

        }
        temp = temp->next;
    }

    return false;
    
}

void deletion(Node* &head, int val){

    Node* temp = head;
    if(temp->data ==val){
        head  = temp->next;
        return;

    }
    
    while(temp->next->data!=val){
    temp =temp->next;
    }
    Node* node = temp->next->next;
    temp->next = node;
}


/*--------MIDDLE OF THE LINKED LIST----------
Given a non-empty, singly linked list with head node head, 
return a middle node of linked list.

If there are two middle nodes, return the second middle node.
*/

        Node* findMiddle(Node* head){
            if(head == NULL){
                return NULL;
            }

            Node* sPtr = head;
            Node* fPtr = head;

            while(fPtr && fPtr->next){
                sPtr = sPtr->next;
                fPtr = fPtr->next;

                    if(fPtr){
                        fPtr = fPtr->next;
                    }
            }

            return sPtr;


        }


int main(){
    Node* head = new Node(1);

    insertLast(head, 2);
    insertLast(head, 3);
    insertLast(head, 4);
    insertLast(head, 5);

    display(head);

    cout<<findMiddle(head)->data<<endl;
    



    return 0;
}