	int gcd=l[0];
	int i=1;
	while(i<l.size())
	{
		while(l[i]%gcd!=0)
		{
			gcd++;
		}
		i++;
	}
	lcm=lcm*gcd;
	return lcm;
}
<|endoftext|>