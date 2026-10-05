	int count = 0;
	while(n != 0) {
		n = n / 10;
		count++;
	}
	return count;
}
int main() {
	int i = 12345;
	cout << countDigit(i);
	return 0;
}
<|endoftext|>