	string stack;
	map<char,char> parentheses = {{')','('},']','['},'}','{'};
	for(int i=0;i<str1.size();i++){
		if(str1[i] == '(' || str1[i] == '[' || str1[i] == '{'){
			stack.push_back(str1[i]);
		}
		else{
			if(stack.empty()){
				return false;
			}
			char popped = stack.back();
			stack.pop_back();
			if(parentheses[str1[i]] != popped){
				return false;
			}
		}
	}
	return stack.empty();
}
<|endoftext|>