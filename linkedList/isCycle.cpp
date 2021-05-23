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
        head = node;
        return ;
    }

    Node* temp = head;

    while (temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=node;

}

void display(Node* head){
    Node* temp = head;

    while(temp!=NULL){
        cout<<temp->data<<"->";

        temp = temp->next;
    }
    cout<<endl;

}

void printCycle(Node* juntion){
    if(juntion==NULL){
        cout<<"No cycle present";
        return;
    }
    else{

        cout<<"cylcle :\n";

    Node* temp = juntion;

    do{
        cout<<temp->data<<"->";
        temp =temp->next;
    } while ( temp!=juntion);

    }
    

}

Node* findJunction(Node* head){
    if(head==NULL){
        return NULL;
    }

    Node* slow = head;
    Node* fast = head;

    
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next;


        if(fast){
            fast = fast->next;
        }

        if(slow==fast){               //if at any iteration, slow = fast then it means cycle!

            //to find the junction point, move slow/fast to head node and start increment both by 1 step till they are equal
            slow=head;

            while(slow!=fast){
                slow = slow->next;
                fast = fast->next;
            }
            return slow;  //junction node
        }
    }

    return NULL;  //if no cycle


}


int main(){
    Node* head = new Node(1);

     head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->next = head->next->next;
    

    Node* junc = findJunction(head);
    printCycle(junc);



    return 0;
}