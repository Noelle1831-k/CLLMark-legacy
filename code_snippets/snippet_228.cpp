	double result = 0;
	for (int i = 1; i <= n; i++) {
		result += 1 / i;
	}
	return result;
}
int main() {
	int n;
	cin >> n;
	cout << harmonicSum(n) << endl;
	return 0;
}
<|endoftext|>