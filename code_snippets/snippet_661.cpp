	string::iterator itr=num.begin();
	while(itr!=num.end()){
		if(*itr>='0'&&*itr<='9'&&!(*itr=='.'||itr==num.end()))
			itr++;
		else 
			return false;
	}
	return true;
}
<|endoftext|>