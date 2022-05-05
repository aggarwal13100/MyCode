/*************************************************
    
    class Node {
        public :

        int data;
        Node *next;

        Node(int data) {
            this -> data = data;
            this -> next = NULL;
        }
    };

*************************************************/

Node *removeLoop(Node *head)
{
	//return NULL if list is NULL
    if(head==NULL){
		return head;
	}
	else{
		//using floyd cycle detection algorithm
		//slow pointer moves 1 step
		//fast pointer moves 2 step
		Node* slow=head;
		Node* fast=head;
		//if fast or slow pointer meet NULL then
		//no cycle present so return head
		while(slow!=NULL && fast!=NULL){
			//moving fast 1 step
			fast=fast->next;
			//moving fast 2 step if it is not pointing to NULL
			//in 1 step
			if(fast!=NULL){
				fast=fast->next;
			}
			//moving slow 1 step
			slow=slow->next;
			//if slow and fast pointer pointing to same
			//then cycle is present and now
			//checking for starting of loop
			if(slow==fast){
				//making slow pointing to head
				slow=head;
 				//moves both slow and fast 1 step until they meet
				while(slow!=fast){
					fast=fast->next;
					slow=slow->next;
				}
 				//removing loop by removing next pointer of 
				//loop and set it to null
				Node* temp=slow;
				while(temp->next!=slow){
					temp=temp->next;
				}
				temp->next=NULL;
				//retuning the head of updated list
				return head;
			}
		}
		return head;
	}
}
