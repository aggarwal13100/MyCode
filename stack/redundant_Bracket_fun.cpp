#include<stack>
bool findRedundantBrackets(string &s)
{
    stack<char> stk;
	//traversing the loop
	for(int i=0;i<s.length();i++){
		//push all elements until get ')'
		if(s[i]!=')'){
			stk.push(s[i]);
		}
		//found ')'
		else{
			//if top element "(" so-CASE : "()"
			if(stk.top()=='('){
				return true;
			}
			//maintain count for operation - +,-,*,/
			int count=0;
			
			//pop element until get pair of closing bracket
			while(stk.top()!='('){
				//opertion found increment count
				if(stk.top()=='+' ||
				  stk.top()=='-' ||
				  stk.top()=='*' ||
				  stk.top()=='/'){
					count++;
				}
				//removing top element
				stk.pop();
			}
			
			//removing opening bracket- '('
			stk.pop();
			
			//NOT found any operation in between () so return true
			if(count==0){
				return true;
			}
		}
	}
	
	//NOT found any redundant bracket return false
	return false;
}
