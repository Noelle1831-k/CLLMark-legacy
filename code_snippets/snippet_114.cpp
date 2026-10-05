	if (n <= 0)
		return 0;
	else if (n == 1)
		return 30;
	else {
		int i = 2;
		while (i <= n) {
			int p = n-i;
			if (p % 3 == 0)
				n -= 3*i;
			else {
				p /= 3;
				while (p % 3 != 0)
					p /= 3;
				n -= i*p;
			}
			i++;
		}
		return n;
	}
}
int main() {
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		cout << smartnumber(n) << endl;
	}
	return 0;
}
<|endoftext|>