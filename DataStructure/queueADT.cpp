#include<iostream>
#include<climits>
#include"linkedList.h"
using namespace std;


class QueueLL{

    public:
    linkList l;
    
    //insert element at tail of linked list
    void enque(int d){
        
        l.insertAtTail(d);

    }
    //remove element at the head of linked list
    int deque(){
        if(l.isEmpty()){
            return INT_MIN;
        }
        else{
            node* temp=l.head;
            int d=temp->data;
            l.deleteAtposition(1);
            return d;
        }
    }
    //It tells whether the queue is empty or not
    bool isempty(){
        return l.isEmpty();
    }

    //It shows the front element of the linked list
    int Front(){
        if(l.isEmpty()){
            return INT_MIN;
        }
        else{
            return l.head->data;
        }
    }

    //It show the size i.e., no of elements in the linked list
    int Size(){
        if(l.isEmpty()){
            return INT_MIN;
        }
        else{
            return l.size;
        }
    }
};

//It display the queue 'q' entered
void display(QueueLL q){
    int num=q.Size();
    for(int i=0;i<num;i++){
        int temp=q.deque();
        cout<<temp<<" ";
        q.enque(temp);
    }
}

void menu(){
    cout<<"Enter 1 : To add an element\n";
    cout<<"Enter 2 : To remove an element\n";
    cout<<"Enter 3 : To display front element\n";
    cout<<"Enter 4 : To check Queue is empty or not\n";
    cout<<"Enter 5 : To Display Queue\n";
    cout<<"Enter 6 : To Display Size of Queue\n";
    cout<<"Enter 0 : To Exit\n";
}
int main(){

    QueueLL q1;
    menu();
   int num=1;
    //Driver's code
    while(num!=0){
        cout<<"\nenter your choice : ";
        cin>>num;
        if(num==1){
            int k;
            cout<<"\nEnter an element : ";
            cin>>k;
            q1.enque(k);
            cout<<"\n----**** Data inserted successfully with value : "<<k<<" ****----\n"<<endl;
        }
        else if(num==2){
            int d=q1.deque();
            if(d==INT_MIN){
                cout<<"\n----**** Queue is empty ****----\n"<<endl;
            }
            else{
                cout<<"\n----**** Data popped out successfully with value : "<<d<<" ****----\n"<<endl;
            }
        }
        else if(num==3){
            int d=q1.Front();
            if(d==INT_MIN){
                cout<<"\n----**** Queue is empty ****----\n"<<endl;
            }
            else{
                cout<<"\nFront ---> "<<d<<endl<<endl;
            }
        }
        else if(num==4){
            if(q1.isempty()){
                cout<<"\n----****Queue is empty****----\n";
            }
            else
                cout<<"\n----****Queue is not empty****----\n";
        }
        else if(num==5){
            cout<<endl;
            if(q1.isempty()){
                cout<<"\n----****Queue is empty****----\n";
            }
            else
                display(q1);
            cout<<endl;
        }
        else if(num==6){
            int d=q1.Size();
            if(d==INT_MIN){
                cout<<"\n----**** Queue is empty ****----\n"<<endl;
            }
            else{
                cout<<"\nSize  -  "<<d<<endl<<endl;
            }
        }
        else if(num==0){
            break;
        }
        else{
            cout<<"\n----****Wrong Input****----\n";
        }
    }
    return 0;
}