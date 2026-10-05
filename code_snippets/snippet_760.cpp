	if (n <= 1)
		return n;
	else
		return fibonacci(n - 1) + fibonacci(n - 2);
}
int main() {
	cout << fibonacci(7) << endl;
	cout << fibonacci(8) << endl;
	cout << fibonacci(9) << endl;
}
<|endoftext|>