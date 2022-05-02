#include <iostream>
using namespace std;
class Stack{
    public:
   
    int *arr;
    int size;
    int top;
   
    //constructor
   
    Stack(int s){
        arr=new int[s];
        top=-1;
        size=s;
    }
   
    //push an element if stack is not full
   
    void push(int num){
        //insert element if size of stack is not full
        if(top+1<=size-1){
            arr[++top]=num;
        }
        //if stack is full
        else
        cout<<"Stack Overflow";
    }
   
    //return and remove last inserted element if existed
   
    int pop(){
        //return -1 if nothing is in Stack
        if(top<0){
            cout<<"Stack underflow";
            return -1;
        }
        else{
            //storing top element
            int temp=arr[top];
            //decrement top
            top=top-1;
            //returning top element
            return temp;
        }
    }
   
    //return last inserted element
   
    int peek(){
        //return -1 if nothing is in Stack
        if(top<0){
            cout<<"Stack underflow";
            return -1;
        }
        else{
            //returning top Element
            return arr[top];
        }
    }
   
    //return true if stack is empty otherwise return false
   
    bool isEmpty(){
        if(top<0){
            return true;
        }
        else
            return false;
    }
};
void menu(){
    cout<<"Enter 1 : To add an element\n";
    cout<<"Enter 2 : To remove an element\n";
    cout<<"Enter 3 : To display top element\n";
    cout<<"Enter 4 : To check Stack is empty or not\n";
    cout<<"Enter 0 : To Exit\n";
}
int main() {
    int n;
    cout<<"Enter the size of Stack"<<endl;
    cin>>n;
    Stack myStack(n);               //Constructing Stack
    int num=1;
   
    //display menu
   
    menu();
   
    //Driver's code
    while(num!=0){
        cout<<"\nenter your choice : ";
        cin>>num;
        if(num==1){
            int k;
            cout<<"\nEnter an element : ";
            cin>>k;
            myStack.push(k);
            cout<<"\n----****Element inserted****----\n";
        }
        else if(num==2){
            cout<<"\n----****Element removed****----\n"<<myStack.pop();
        }
        else if(num==3){
            cout<<"\nTop ---> "<<myStack.peek()<<endl;
        }
        else if(num==4){
            if(myStack.isEmpty()){
                cout<<"\n----****Stack is empty****----\n";
            }
            else
                cout<<"\n----****Stack is not empty****----\n";
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