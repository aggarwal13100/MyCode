void solve(stack<int> &inputStack,int count, int size){
  //if count is half of size then delete element and return the Stack
	if(count==(size/2)){
		inputStack.pop();
		return;
	}
  //if Stack is not empty then increment count
	count++;
  //Store top element of Stack and then pop that element
	int temp=inputStack.top();
	inputStack.pop();
  //call the recursive function
	solve(inputStack,count,size);
  //Now again entered the stored element
	inputStack.push(temp);
}

void deleteMiddle(stack<int>&inputStack, int N){
	//maintain the count to track position
	int count=0;
  //solving function through recursion
	solve(inputStack,count,N);
	return;
}
