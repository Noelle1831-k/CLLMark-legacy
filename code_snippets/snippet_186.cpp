	string first = lst[0];
	for(int i = 1; i < lst.size(); i++){
		if(first != lst[i])
			return false;
	}
	return true;
}
<|endoftext|>