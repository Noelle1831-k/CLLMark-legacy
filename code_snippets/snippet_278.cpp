	unsigned int m = n, i = 0;
	while(m & 1)
	{
		m >>= 1;
		i++;
	}
	m ^= 1 << (i-1);
	return m;
}
<|endoftext|>