Node* reverse(Node* &first){
    Node* prev=NULL;
    while(first!=NULL){
        Node* forward=first->next;
        first->next=prev;
        prev=first;
        first=forward;
    }
    return prev;    
}
class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        //reversing the linked list
        Node* temp1=reverse(first);
        Node* temp2=reverse(second);
        Node* head=NULL;
        int carry=0;
        //adding the linked list
        while(temp1!=NULL && temp2!=NULL){
            int sum=temp1->data+temp2->data+carry;
            carry=sum/10;
            Node* temp=new Node(sum%10);
            temp->next=head;
            head=temp;
            temp1=temp1->next;
            temp2=temp2->next;
        }
        //increasing the linked list if first list is not empty
        while(temp1!=NULL){
            int sum=temp1->data+carry;
            carry=sum/10;
            Node* temp=new Node(sum%10);
            temp->next=head;
            head=temp;
            temp1=temp1->next;
        }
        //increasing the linked list if second list is not empty
        while(temp2!=NULL){
            int sum=temp2->data+carry;
            carry=sum/10;
            Node* temp=new Node(sum%10);
            temp->next=head;
            head=temp;
            temp2=temp2->next;
        }
        //if last digit sum carry is not zero then add it to the end of list
        if(carry!=0){
            Node *temp=new Node(carry);
            temp->next=head;
            head=temp;
        }
        return head;
    }
};
