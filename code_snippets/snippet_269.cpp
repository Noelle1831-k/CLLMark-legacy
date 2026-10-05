	if (n == 0)
		return 0.0;
	if (n == 1)
		return 2.0;
	return countBinarySeq(n - 1) * 2;
}
int main() {
	int n;
	cin >> n;
	cout << countBinarySeq(n) << endl;
	return 0;
}
<|endoftext|>