	int result = 0;
	while (n % 2 == 0) {
		result += 2;
		n /= 2;
	}
	for (int i = 3; i < n; i += 2) {
		while (n % i == 0) {
			result += i;
			n /= i;
		}
	}
	if (n > 2)
		result += n;
	return result;
}
int main() {
	cout << sum(40) << endl;
	return 0;
}
<|endoftext|>