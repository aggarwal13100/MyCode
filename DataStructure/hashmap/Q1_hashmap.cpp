#include <iostream>
using namespace std;
class node{
    public:
    string key;
    float value;
    node(string s,float d){
        key=s;
        value=d;
    }
};
class hashmap
{
public:
    node* arr[10]={NULL};
    
    void insert(string s,float d){
        //taking hash code
        int code=hashcode(s);

        //compression by hash function h(x)= x % 10
        int index=code%10;

        //maintain count to stop while loop if no space is empty
        int count=1;
        while(arr[index]!=NULL && arr[index]->key!=" " && count<=10){
            //update key value if present already 
            if(arr[index]->key==s){
                arr[index]->value=d;
                return;
            }
            index=(index+1)%10;
            count++;
        }
        if(count<=10){

            arr[index]=new node(s,d);
        }
        else
        {
            std::cout << "size full" << std::endl;
        }
    }

    void del(string k){
        //taking hash code
        int code=hashcode(k);

        //compression by hash function h(x)= x % 10
        int index=code%10;

        //maintain count to stop while loop if we don't found element
        int count=1;
        while(arr[index]!=NULL && count<10){
            if(arr[index]->key==k){
                break;
            }
            index=(index+1)%10;
            count++;
        }
        if(arr[index]!=NULL && count<10){
            arr[index]->key=" ";
            arr[index]->value=0;
        }
        else
        {
            cout<<"Invalid key"<<endl;
        }
    }

    float keyValue(string s){
        //taking hash code
        int code=hashcode(s);

        //compression by hash function h(x)= x % 10
        int index=code%10;

        //maintain count to stop while loop if don't find key
        int count=1;
        while(arr[index]!=NULL && count<10){
            if(arr[index]->key==s){
                break;
            }
            index=(index+1)%10;
            count++;
        }
        if(arr[index]!=NULL && count<10){
            return arr[index]->value;
        }
        else
        {
            return -1;
        }
    }

    void displayMap(){
        int index=0;
        for(node* var : arr)
        {
            if(var!=NULL){
                cout << index << " - " << var->key << " : " << var->value << endl;
            }
            index++ ;
        }
    }

    //generate hash code for key
    int hashcode(string key){
        int index=1;
        int code=0;
        for(char ch : key)
        {
            code+=(int(ch)*index++);        
        }
        return code;
    }
};

void menu(){
    cout << "Enter 1 for insert data"<<endl;
    cout << "Enter 2 for delete" << endl;
    cout << "Enter 3 for search" <<endl;
    cout << "Enter 4 for display Map" << endl;
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
            float ans=h.keyValue(key);
            if(ans==-1){
                cout<<"\n\nInvalid Key\n\n"<<endl;
            }
            else{
                cout<<"\n\nStudent's height - "<<ans<<endl<<endl;
            }
        }
        else if (choice == 4){
            cout << endl;
            h.displayMap();
            cout << endl;
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