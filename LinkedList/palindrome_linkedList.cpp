struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution{
  public:
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        Node* temp=head;
        int count=0;            //count length of linked list
        //traversing the linked list
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        //if length is odd then we do +1 then divide by 2
        if(count&1==1){
            count=count+1;
        }
        // if length is even then only divide by two
        //because we want to at middle element
        count=count/2;
        temp=head;
        //count-- take us to next to middle element
        while(count--){
            temp=temp->next;
        }
        Node* temp1=head;
        Node* prev=NULL;
        //reverse the linked list after middle element
        while(temp!=NULL){
            Node* forward=temp->next;
            temp->next=prev;
            prev=temp;
            temp=forward;
        }
        //Now checking for linked list is palindrome or not
        while(prev!=NULL){
            if(temp1->data!=prev->data){
                return false;
            }
            prev=prev->next;
            temp1=temp1->next;
        }
        return true;
        
    }
};
