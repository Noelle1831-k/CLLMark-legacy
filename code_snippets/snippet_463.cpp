	if (n <= 2)
		return n;
	int f0 = 0, f1 = 1, f2 = 1; 
	while (n > 2) {
		f0 = f1;
		f1 = f2;
		f2 = f0 + f1;
		n--;
	}
	return f2;
}
int main() {
	int n = 5;
	cout << "Jacobsthal-Lucas " << n << "th value: " << jacobsthalLucas(n) << endl;
	return 0;
}
<|endoftext|>