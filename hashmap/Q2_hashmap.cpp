#include<iostream>
using namespace std;
class node{
    public:
    string key;
    float data;
    node* next;
    node(string s,float d){
        key=s;
        data=d;
        next=NULL;
    }
};

class hashmap{
    public:
    node* arr[10]={NULL};
    node* tail[10]={NULL};
    void insert(string s, float d){
        //generate hashcode for given key-s
        int code=hashcode(s);

        //code compression
        int index=code%10;

        if(arr[index]==NULL){
            arr[index]=new node(s,d);
            tail[index]=arr[index];
        }
        else{
            node* temp=new node(s,d);
            tail[index]->next=temp;
            tail[index]=temp;
        }
    }

    void del(string s){
        //generate hashcode for given key-s
        int code=hashcode(s);

        //code compression
        int index=code%10;

        if(arr[index]==NULL){
            cout<<"Invalid Key"<<endl;
        }
        else{
            node* curr=arr[index];
            node* prev=NULL;
            while(curr!=NULL && curr->key!=s){
                prev=curr;
                curr=curr->next;
            }
            if(curr==NULL){
                cout<<"Invalid Key"<<endl;
            }
            else
            {
                if(prev!=NULL){
                    prev->next=curr->next;
                    delete curr;
                }
                else{
                    arr[index]=curr->next;
                    delete curr;
                }
            }
        
        }
    }
    float display(string s){
        //generate hashcode for given key-s
        int code=hashcode(s);

        //code compression
        int index=code%10;

        if(arr[index]==NULL){
            return -1;
        }
        else{
            node* curr=arr[index];
            while(curr!=NULL && curr->key!=s){
                curr=curr->next;
            }
            if(curr==NULL){
                return -1;
            }
            else
            {
                return curr->data;
            }
        
        }

    }

    //generate hash code for key
    int hashcode(string key){
        int code=0;
        for(char ch : key)
        {
            code+=int(ch);        
        }
        return code;
    }
};

void menu(){
    cout<<"Enter 1 for insert data"<<endl;
    cout << "Enter 2 for delete" << endl;
    cout << "Enter 3 for search" <<endl;
    cout << "Enter 0 for exit" << endl;
}

int main ()
{
    hashmap h;
    menu();
    int choice=1;
    while (choice!=0)
    {
        cout<<"Enter your choice : ";
        cin>>choice;
        cout<<endl;
        if (choice==1)
        {
            string key;
            cout<<"\nEnter name of student : ";
            cin.ignore();
            getline(cin,key);
            float data;
            cout<<"\nEnter height of the student : ";
            cin>>data;
            h.insert(key,data);
            cout<<"\n\nData inserted with key - "<<key<<" and value - "<<data<<endl<<endl;
        }
        else if (choice==2)
        {
            string key;
            cout<<"\nEnter name of student : ";
            cin.ignore();
            getline(cin,key);
            h.del(key);
            cout<<"\n\nData deleted with key - "<<key<<endl<<endl;
        }
        else if (choice==3)
        {
            string key;
            cout<<"\nEnter name of student : ";
            cin.ignore();
            getline(cin,key);
            float ans=h.display(key);
            if(ans==-1){
                cout<<"\n\nInvalid Key\n\n"<<endl;
            }
            else{
                cout<<"\n\nStudent's height - "<<ans<<endl<<endl;
            }
        }
        else if(choice==0){
            break;
        }
        else
        {
            cout<<endl<<"\nWrong input\n"<<endl;
        }
    }
    return 0;
}