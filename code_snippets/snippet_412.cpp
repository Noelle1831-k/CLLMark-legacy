	if(l.size() == 0){
		return false;
	}
	int i = 0;
	while(i < l.size()){
		while(i < l.size() && l[i] == l[i-1])
		{
			i++;
		}
		while(i < l.size() && l[i] > l[i-1])
		{
			i++;
		}
	}
	if(i >= l.size()){
		return true;
	}
	return false;
}
<|endoftext|>