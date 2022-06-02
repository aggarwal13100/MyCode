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

//function to display the linked list
void display(linkList l){

    node* temp=l.head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
void menu (){
    cout << "\nEnter 1 to insert Data at head of linked list\n";
    cout << "Enter 2 to insert Data at tail of linked list\n";
    cout << "Enter 3 to insert Data at position in linked list\n";
    cout << "Enter 4 to Delete Data at position in linked list\n";
    cout << "Enter 5 to search Data in linked list\n";
    cout << "Enter 6 to check Data is present at position in linked list\n";
    cout << "Enter 7 to check linked list is empty or not\n";
    cout << "Enter 8 to Display Elements of linked list\n";
    cout << "Enter 0 to stop\n"<<endl;
}
int main (){
    linkList l;

    int num=1;
    menu();
    while(num!=0){
        cout << "\nEnter your choice "<<endl;
        cin >> num;

        if(num==1){
            cout << "\nEnter data : ";
            int n;
            cin >> n;
            l.insertAtHead(n);
        }
        else if(num==2){
            cout << "\nEnter data : ";
            int n;
            cin >> n;
            l.insertAtTail(n);
        }
        else if(num==3){
            cout<<"\nEnter data : ";
            int n;
            cin >> n;
            cout << "Enter Position : ";
            int p;
            cin >> p ;
            l.insertAtPosition(p,n);
        }
        else if(num==4){
            cout << "\nEnter Position : ";
            int p;
            cin >> p;

            l.deleteAtposition(p);
        }
        else if(num==5){
            cout << "\nEnter data : ";
            int n,ans;
            cin >> n;
            ans=l.search(n);
            if(ans==1){
                cout << "\nElement is present"<<endl;
            }
            else if (ans==0){
                cout << "\nElement is not present"<<endl;
            }
        }
        else if (num==6){
            int p,d;
            cout << "\nEnter data : ";
            cin >> d;
            cout << "Enter Position : ";
            cin >> p;
            int n,ans;
            ans=l.searchAtPosition(p,d);
            if(ans==1){
                cout << "\nElement "<<d<<" is present at position "<<p<<endl;
            }
            else if (ans==0){
                cout << "\nElement "<<d<<" is not present at position "<<p<<endl;
            }
        }
        else if(num==7){
            bool ans;
            ans=l.isEmpty();
            if(ans){
                cout << "\nLinked list is Empty"<< endl;
            }
            else{
                cout << "\nLinked list is not Empty"<<endl;
            }
        }
        else if(num==8){
            cout << endl;
            if(l.isEmpty()){
                cout << "\nLinked List is Empty"<<endl;
            }
            else{
                display(l);
            }
            cout << endl;
        }
        else if(num==0){
            break;
        }
        else{
            cout << "\nWrong Input\n";
        }
    }
    return 0;
}