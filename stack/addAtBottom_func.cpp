void solve(stack<int>& myStack, int x){
  //if Stack is empty then insert element
	if(myStack.empty()){
		myStack.push(x);
		return;
	}
  //if Stack is not empty then store top and then remove it
	int num=myStack.top();
	myStack.pop();
  //Now call solve after poping last element
	solve(myStack,x);
  //Now push stored element in the Stack
	myStack.push(num);
}
stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
  //making a function to add element at bottom of Stack
  solve(myStack,x);
	return myStack;
}
