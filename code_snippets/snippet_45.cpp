	while (a * b > 10) {
		a, b = b, a * b % 10;
	}
	return a * b % 10;
}
int main() {
	int a, b;
	cin >> a >> b;
	cout << computeLastDigit(a, b);
	return 0;
}
<|endoftext|>