	string::iterator itr=n.begin();
	while(itr!=n.end()-1)
	{
		if(*itr!=*(itr+1))
			return false;
		itr++;
	}
	return true;
}
<|endoftext|>