	int i = n, num = 0;
	while (i > 0) {
		num += (i - 1) * 2 * i;
		i--;
	}
	return num;
}
int main() {
	int n;
	cin >> n;
	cout << centeredHexagonalNumber(n);
	return 0;
}
<|endoftext|>