	int count = 0;
	while (n != 1) {
		count++;
		if (n % 2 == 0) {
			n /= 2;
		} else if (n % 2 == 1) {
			if (n % 3 == 0) {
				n /= 3;
			} else if (n % 3 == 1) {
				n -= 1;
			} else {
				n += 1;
			}
		}
	}
	return count;
}
int main() {
	int n;
	cin >> n;
	cout << isPolite(n);
}
<|endoftext|>