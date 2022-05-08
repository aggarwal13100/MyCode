void insertBottom(stack<int> &stack, int num){
	//if stack is empty then push element
	if(stack.empty()){
		stack.push(num);
		return;
	}
	//store top element and remove it
	int n=stack.top();
	stack.pop();
	
	//recursion call
	insertBottom(stack,num);
	
	//push back stored element
	stack.push(n);
}
void reverseStack(stack<int> &stack) {
    //if stack is empty return stack
	if(stack.empty()){
		return;
	}
	
	//store top element and remove it
	int num=stack.top();
	stack.pop();
	
	//Recursion call
	reverseStack(stack);
	
	//enter stored element at bottom of stack
	insertBottom(stack,num);
}
