	for (int i = 2; i < n; i++) {
		if (n % i == 0) {
			return true;
		}
	}
	return false;
}
int main() {
	int n;
	cin >> n;
	while (n != 0) {
		if (isNotPrime(n)) {
			cout << "Prime" << endl;
		} else {
			cout << "Not prime" << endl;
		}
		cin >> n;
	}
	return 0;
}
<|endoftext|>