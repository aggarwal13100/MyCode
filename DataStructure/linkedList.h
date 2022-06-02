#include<iostream>
using namespace std;
#include<climits>

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
};

class linkList{
    public:
    //it track the size of the array
    int size=0;
    node* head=NULL;
    node* tail=NULL;

    void insertAtHead(int d){
        //It insert the data 'd' at the head of linked list

        //linked list has no element
        if(head==NULL){
            head=new node(d);
            tail=head;
        }
        else{
            node* temp=new node(d);
            temp->next=head;
            head=temp;
        }
        //increase linked list size by 1
        size++;
    }


    void insertAtTail(int d){
        //It insert the data 'd' at the tail of linked list
        //linked list has no element
        if(tail==NULL){
            tail=new node(d);
            head=tail;
        }
        else{
            node* temp=new node(d);
            tail->next=temp;
            tail=tail->next;
        }
        //increase the size of linked list
        size++;  
    }


    int search(int d){
        //It search the data 'd' in linked list

        //If no element present then it return -1
        if(isEmpty()){
            cout << "No Element Exist"<<endl;
            return -1;
        }

        //if element found then it returns true otherwise false
        else{
            node* temp=head;
            while(temp!=NULL){
                if(d==temp->data){
                    return 1;
                }
                temp=temp->next;
            }
            return 0;
        }
    }


    bool isEmpty(){
        //It return true if linked list is empty otherwise false
        return head==NULL;
    }


    void insertAtPosition(int position,int d){
        //It insert the given data 'd' at position

        //if position is not in range
        if(position<=0 || position>(size+1)){
            // cout<<size<<endl;
            cout << "Range Out of Bound"<<endl;
        }
        //if position is 1 then call InsertAtHead
        else if(position==1){
            insertAtHead(d);
            return;
        }
        //if position is size+1 i.e.,at last then call InsertAttail
        else if(position==size+1){
            insertAtTail(d);
            return;
        }
        else{
            //Taking a value of head in temp
            node* temp=head;
            int count=1;
            //Traverse to the given position
            while(count<position-1){
                temp=temp->next;
                count++;
            }

            node* nodeToInsert=new node(d);
            nodeToInsert->next=temp->next;
            temp->next=nodeToInsert;
            //incresing the size of linked list
            size++;
        }
    }
    void deleteAtposition(int position){
        // It removes the node at the given position

        // not a valid position
        if(position<=0 || position>size){
            cout<< "Range Out of bound"<<endl;
        }
        //delete at head
        else if(position==1){
            node* temp=head;
            head=head->next;
            //only one element is present updata both head and tail
            if(head==NULL){
                tail=NULL;
            }
            temp->next=NULL;
            delete temp;
            size--;
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

            //delete at tail then update tail
            if(temp->next==NULL){
                prev->next=NULL;
                tail=prev;
                delete temp;
            }
            else{
                prev->next=temp->next;
                delete temp;
            }

            //decrement the size of linked list
            size--;
        }
    }
    int searchAtPosition(int position,int d){
        //It return true if given data 'd' is present at position otherwise return false

        //not valid range
        if(position<=0 ||position >size){
            cout<< "Range Out of Bound"<<endl;
            return -1;
        }
        else{
            int count=1;
            node* temp=head;
            while(count<position){
                temp=temp->next;
                count++;
            }
            if(temp->data==d){
                return 1;
            }
            else{
                return 0;
            }
        }
    }
};