	if(n <= 0)
		return 0;
	if(n == 1)
		return 1;
	if(n == 2)
		return 1;
	int p = 0, c = 1, r = 1;
	while(c < n) {
		p = c;
		c = r;
		r = p + r;
	}
	return r;
}
int main() {
	int n = 10;
	cout << sequence(n);
	return 0;
}
<|endoftext|>