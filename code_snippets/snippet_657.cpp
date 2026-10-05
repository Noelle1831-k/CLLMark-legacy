	if(n<=0)
		return 0;
	if(n==1)
		return 1;
	if(n==2)
		return 1;
	return jacobsthalNum(n-1)+2*jacobsthalNum(n-2);
}
<|endoftext|>