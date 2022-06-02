#include <iostream>
#include<climits>
#include"linkedList.h"
using namespace std;

class StackLL{
    
    linkList l;

    public:
    //inserting data into stack using linked list(adding on head)
    void push(int d){
        l.insertAtHead(d);
    }

    //It returns and remove top element
    int pop(){

        //If stack is empty it returns min Integer value
        if(l.isEmpty()){
            return INT_MIN;
        }
        //If stack is not empty 
        else{
            node* temp=l.head;
            int mydata=temp->data;
            l.deleteAtposition(1);
            return mydata;
        }
    }
    bool isEmpty(){
        return l.isEmpty();
    }

    //It returns the Top Element of the Stack
    int Top(){

        if(l.isEmpty()){
            return INT_MIN;
        }
        else{
            return l.head->data;
        }
    }

};
    //Display the Stack Elements
    void Display(StackLL s){

        if(s.isEmpty()){
            return;
        }

        int topElement=s.pop();
        cout<<topElement<<" ";

        Display(s);

        s.push(topElement);
    }
void menu(){

    cout<<"Enter 1 : To add an element\n";
    cout<<"Enter 2 : To remove an element\n";
    cout<<"Enter 3 : To display top element\n";
    cout<<"Enter 4 : To check Stack is empty or not\n";
    cout<<"Enter 5 : To Display Stack\n";
    cout<<"Enter 0 : To Exit\n";
}
int main(){
    
    
    StackLL myStack;
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

            myStack.push(k);
            cout<<"\n----**** Data inserted successfully with value : "<<k<<" ****----\n"<<endl;
        }

        else if(num==2){

            int d=myStack.pop();

            if(d==INT_MIN){
                cout<<"\n----**** Stack is empty ****----\n"<<endl;
            }
            else{
                cout<<"\n----**** Data popped out successfully with value : "<<d<<" ****----"<<endl;
            }
        }

        else if(num==3){

            int d=myStack.Top();

            if(d==INT_MIN){
                cout<<"\n----**** Stack is empty ****----\n"<<endl;
            }
            else{
                cout<<"\nTop ---> "<<d<<endl<<endl;
            }
        }

        else if(num==4){

            if(myStack.isEmpty()){
                cout<<"\n----****Stack is empty****----\n";
            }
            else
                cout<<"\n----****Stack is not empty****----\n";
        }

        else if(num==5){

            if(myStack.isEmpty()){
                cout<<"\n----****Stack is empty****----\n";
            }
            else
                cout<<endl;
                Display(myStack);
                cout<<endl;
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
