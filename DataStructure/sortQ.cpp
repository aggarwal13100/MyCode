#include<iostream>
#include<queue>
#include<climits>
using namespace std;

queue<int> sortq(queue<int> q,int size){
    //auxiliary queue
    queue<int> newq;
    while(!q.empty()) {
        //sorting queue using selection sort

        //taking first element to be minimum
        int mini=q.front();
        
        //removing front and decrement size
        q.pop();
        size--;

        //now finding minimum element
        for(int i=0;i<size;i++) {
            int temp=q.front();
            q.pop();
            if(temp<mini){
                q.push(mini);
                mini=temp;
            }
            else{
                q.push(temp);
            }
        }

        //insert minimum element in auxiliary array
        newq.push(mini);
    }
    return newq;
}

//function to display the whole queue
void display(queue<int> q){
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
}
int main(){
    queue<int> q;
    cout << "Enter size of queue"<<endl;
    int size;
    cin>>size;
    cout<<"\nEnter elements of queue seperated by spaces"<<endl;
    for(int i=0;i<size;i++){
        int num;
        cin>>num;
        q.push(num);
    }
    cout<<endl;
    q=sortq(q,size);
    display(q);
    return 0;
}