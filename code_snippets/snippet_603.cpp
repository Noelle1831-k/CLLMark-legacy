	if (a == 0)
		return b;
	if (b == 0)
		return a;
	if (a == b)
		return a;
	if (a > b)
		return recurGcd(a-b, b);
	return recurGcd(a, b-a);
}
