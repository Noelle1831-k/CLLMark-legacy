	int count = 0;
	while (n != 0) {
		count += (n % 10);
		n = n / 10;
	}
	return count;
}
int main() {
	cout << findDigits(7) << endl;
	cout << findDigits(5) << endl;
	cout << findDigits(4) << endl;
	return 0;
}
<|endoftext|>