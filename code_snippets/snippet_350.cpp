	int f(int i){
		if(i<=0)
		{
			return 0;
		}
		else if(i<=2)
		{
			return 1;
		}
		else
		{
			return max(max(max(f(i/2),f(i/3)),f(i/4)),f(i/5))+i;
		}
	}
	return f(n);
}
<|endoftext|>