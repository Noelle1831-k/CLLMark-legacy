	if (n <= 1)
		return 1;
	if (n % 2 == 1)
		return 2 * getNumber(n - 1, k) + 1;
	else
		return 2 * getNumber(n - 1, k);
}
int main()
{
	int n = 8, k = 5;
	cout << getNumber(n, k);
	return 0;
}
<|endoftext|>