#include<stack>
int findMinimumCost(string str) {
  	stack<char> s;
	int count=0;
	int n=str.length();
  
  //odd length then impossible to make it balanced
	if(n&1==1){
		return -1;
	}
  
	else{
		for(int i=0;i<n;i++){
      
      //push if opening braces
			if(str[i]=='{'){
				s.push(str[i]);
			}
      
      //close braces encounter
			else{
        
        //if stack is empty then push the opening braces and increment reversal count
				if(s.empty()){
					s.push('{');
					count++;
				}
        
        //stack is not empty then pop the opening braces
				else{
					s.pop();
				}
			}
		}
    
    //consider the case {{{{}} then afer for loop left braces are {{
		while(!s.empty()){
      
      //pop two brace with increment the count OR add size_of_Stack/2 in reversal count
			s.pop();
			s.pop();
			count++;
		}
		return count;
	}
}
