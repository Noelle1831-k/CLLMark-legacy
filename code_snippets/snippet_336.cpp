	return ((n % m == 0) ? n : n - n % m + m);
}
int main() {
	int m;
	cin >> m;
	while (m--) {
		int n;
		cin >> n;
		cout << roundNum(n, 10) << endl;
	}
	return 0;
}
<|endoftext|>