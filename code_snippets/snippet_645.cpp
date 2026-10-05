	int i=0;
	while(1)
	{
		string s = to_string(i*(i+1)/2);
		if(s.size()==n)
		{
			return i;
		}
		i++;
	}
	return 0;
}
<|endoftext|>