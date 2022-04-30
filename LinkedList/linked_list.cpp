#include<iostream>
using namespace std;
//define a class node
class node{
    public:
    //it stores data in node
    int data;
    //making a pointer of type node to the next address of node
    node* next;
    //making a constructor and initialize data with given data
    //And next pointer with NULL
    node(int data){
        this->data=data;
        this->next=NULL;
    }
    ~node(){
        int value=this->data;
        if(this->next!=NULL){
            delete next;
            this->next=NULL;
        }
        cout<<"Memory is free for node with data"<<value<<endl;
    }
};
void insertAtHead(node* &head,node* &tail,int d){
    if(head==NULL){
        head=new node(d);
        tail=head;
    }
    else{
        node* temp=new node(d);
        temp->next=head;
        head=temp;
    }
}
void insertAtTail(node* &head,node* &tail,int d){
    if(tail==NULL){
        tail=new node(d);
        head=tail;
    }
    else{
        node* temp=new node(d);
        tail->next=temp;
        tail=tail->next;
    }   
}
void print(node* &t){
    node* n=t;
    //Traverse the linked list until node next pointer points to NULL
    while(n!=NULL){
        cout<<n->data<<" ";
        n=n->next;
    }
    cout<<endl;
}
void insertAtPosition(int position,int d,node* &head,node* &tail){
    //if position is 1 then call InsertAtHead
    if(position==1){
        insertAtHead(head,tail,d);
        return;
    }
    //Taking a value of head in temp
    node* temp=head;
    int count=1;
    //Traverse to the given position
    while(count<position-1){
        temp=temp->next;
        count++;
    }
    //if temp Reaches at last Node then call InsertAtTail
    if(temp->next==NULL){
        insertAtTail(head,tail,d);   //passing tail instead of temp to update tail
        return;
    }
    //if temp not reaches to the last node
    //insert temp at middle
    node* nodeToInsert=new node(d);
    nodeToInsert->next=temp->next;
    temp->next=nodeToInsert;
}
void deleteNode(int position,node* &head,node* &tail){
    if(position==1){
        node* temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
    }
    else{
        node* prev=NULL;
        node* temp=head;
        int count=1;
        while(count<position){
            prev=temp;
            temp=temp->next;
            count++;
        }
        if(temp->next==NULL){
            prev->next=NULL;
            tail=prev;
            delete temp;
        }
        else{
            prev->next=temp->next;
            temp->next=NULL;
            delete temp;
        }
    }
}
int main(){
    node* head=NULL;
    node* tail=NULL;
    // node *n2=new node(20);
    // node *n3=new node(30);
    // node *n4=new node(40);
    // n1->next=n2;
    // n2->next=n3;
    // n3->next=n4;
    // node *n=n1;
    insertAtHead(head,tail,32);
    insertAtTail(head,tail,54);
    insertAtPosition(3,86,head,tail);
    insertAtPosition(1,5,head,tail);
    insertAtPosition(5,1,head,tail);
    print(head);
    cout<<head->data<<endl;
    cout<<tail->data<<endl;
    deleteNode(5,head,tail);
    print(head);
    cout<<head->data<<endl;
    cout<<tail->data<<endl;
    // cout<<n1->data<<" "<<n1->next<<endl;
    // cout<<n2->data<<" "<<n2->next<<endl;
    // cout<<n3->data<<" "<<n3->next<<endl;
    // cout<<n4->data<<" "<<n4->next<<endl;
    return 0;
}