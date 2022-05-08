bool isValidParenthesis(string expression)
{
    //Maintaining a Stack to store and check paranthesis
    stack<char> s;
    //Traversing through the string
    for(int i=0;i<expression.length();i++){
      
    //storing the current element
		char ch=expression[i];
      
    //if it is one of the opening bracket then pushing it on the stack
		if(ch=='(' || ch=='{' || ch=='['){
			s.push(ch);
		}
      
    //if not open bracket then checking for valid close bracket
		else{
      
      //if Stack is empty to pop any element then it is not balanced paranthesis
			if(s.empty()){
				return false;
			}
      
      //if Stack is not empty
			else{
        
        //storing top element
				char t=s.top();
        
        //If bracket matches then pop the open bracket
				if(t=='(' && ch==')' ||
				  t=='{' && ch=='}' ||
				  t=='[' && ch==']'){
					s.pop();
				}
        
        //Bracket doesn't match then return false
				else{
					return false;
				}
			}
		}
	}
  
  //After traversing whole string if stack is not empty then return false (example "(({}" )
	if(s.empty()){
		return true;
	}
	else{
		return false;
	}
}
