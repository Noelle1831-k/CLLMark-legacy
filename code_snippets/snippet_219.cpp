	if (n <= 0 || k <= 0)
		return -1;
	if (n == 1)
		return 1;
	if (n == k)
		return 1;
	if (k == 1)
		return 0;
	return noOfTriangle(n - 1, k - 1) + noOfTriangle(n - k, k);
}
int main() {
	int n, k;
	cin >> n >> k;
	cout << noOfTriangle(n, k);
	return 0;
}
<|endoftext|>