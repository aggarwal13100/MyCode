#include<iostream>
#include<climits>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
    // ~node(){
    //     if(this->next!=NULL){
    //         delete next;
    //         next=NULL;
    //     }
    // }
};
class StackLL{
    //initialising top to be NULL
    node* top=NULL;
    public:
    //inserting data into stack using linked list(adding on head)
    void push(int d){
        //if Stack is empty
        if(isEmpty()){
            //initialise top with data given
            top=new node(d);
        }
        //if stack is not empty
        else{
            //creating new node and pointing its next node to top next node
            node* temp=new node(d);
            temp->next=top;
            //shifting top to new node temp
            top=temp;   
        }
    }
    //It returns and remove top element
    int pop(){
        //If stack is empty it returns min Integer value
        if(isEmpty()){
            return INT_MIN;
        }
        //If stack is not empty 
        else{
            node *temp=top;                 //storing top node
            int popData=top->data;          //storing top data
            top=top->next;                  //assigning top to its next node
            delete temp;                    //deleting node pointed by temp
            return popData;                 //return data
        }
    }
    //tell whether Stack is empty is or not
    bool isEmpty(){
        return top==NULL;
    }
    //It returns the Top Element
    int Top(){
        if(isEmpty()){
            return INT_MIN;
        }
        else{
            return top->data;
        }
    }
    //Display the Stack Elements
    void Display(){
        if(isEmpty()){
            cout<<"----****Stack is Empty****----"<<endl;
        }
        else{
            node* temp=top;
            cout<<"Top ----> "<<temp->data<<endl;
            temp=temp->next;
           while(temp!=NULL){
                cout<<"          "<<temp->data<<endl;
                temp=temp->next;
            }
        cout<<endl;
        }
        
    }
};
void menu(){
    cout<<"Enter 1 : To add an element\n";
    cout<<"Enter 2 : To remove an element\n";
    cout<<"Enter 3 : To display top element\n";
    cout<<"Enter 4 : To check Stack is empty or not\n";
    cout<<"Enter 5 : To Display Stack\n";
    cout<<"Enter 0 : To Exit\n";
}
int main(){
    
    // cout<<"----****Stack is Empty****----"<<endl;
    
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
                cout<<"----**** Data popped out successfully with value : "<<d<<" ****----"<<endl;
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
            myStack.Display();
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