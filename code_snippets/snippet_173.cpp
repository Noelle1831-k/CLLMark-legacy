	int i = 1;
	while (i * i <= n)
	{
		if (n % i == 0)
		{
			if (i * i == n)
				return true;
			else {
				int m = n / i;
				if (m * m == n)
					return true;
			}
		}
		i++;
	}
	return false;
}
<|endoftext|>