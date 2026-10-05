	if(n<=0)
		return 0;
	int i=1,s=0;
	while(i<=n)
	{
		s+=pow(i,4);
		i+=2;
	}
	return s;
}
<|endoftext|>