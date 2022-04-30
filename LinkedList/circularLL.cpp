#include<iostream>
using namespace std;
class node{
    public:
    //store data
    int data;
    //pointer of type node
    node* next;
    //Constructor
    node(int d){
        this->data=d;
        this->
        next=NULL;
    }
    ~node(){
        if(this->next!=NULL){
            delete next;
            next=NULL;
        }
    }
};
void insertAfterValue(node*&tail,int value,int d){
    if(tail==NULL){
        tail=new node(d);
        tail->next=tail;
    }
    else{
        node*temp=tail;
        while(temp->data!=value && temp->next!=tail){
            temp=temp->next;
        }
        if(temp->data!=value){
            cout<<"Value not Found\n";
        }
        else{
            node*forward=new node(d);
            forward->next=temp->next;
            temp->next=forward;
        }
    }
}
void print(node*& tail){
    if(tail==NULL){
        cout<<"Linked List is Empty"<<endl;
    }
    else{
        node* temp=tail;
    while(temp->next!=tail){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<temp->data<<endl;
    }
}
void deleteNode(node*&tail,int value){
    if(tail==NULL){
        cout<<"Linked list is empty"<<endl;
    }
    else{
        node*temp=tail->next;
        node*prev=tail;
        while(temp->data!=value && prev->next!=tail){
            prev=temp;
            temp=temp->next;
        }
        if(temp->data!=value){
            cout<<"Value not Found\n";
        }
        else{
            prev->next=temp->next;
            if(temp->next==temp){
                tail=NULL;
            }
            else if(tail==temp){
                tail=prev;
            }
            temp->next=NULL;
            delete temp;
        }
    }
}
int main(){
    node* tail=NULL;
    insertAfterValue(tail,5,5);
    // deleteNode(tail,5);
    // print(tail);
    insertAfterValue(tail,5,3);
    // print(tail);
    insertAfterValue(tail,3,9);
    // print(tail);
    insertAfterValue(tail,9,1);
    print(tail);
    // cout<<tail->data;
    deleteNode(tail,10);
    print(tail);
    // cout<<tail->data;
    return 0;

}