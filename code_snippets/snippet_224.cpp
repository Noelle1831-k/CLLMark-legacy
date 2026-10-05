	while (1) {
		n++;
		if (sqrt(n)*sqrt(n) == n) {
			return n;
		}
	}
}
int main() {
	int n = 35;
	cout << "nextPerfectSquare(" << n << ") = ";
	cout << nextPerfectSquare(n) << endl;
	return 0;
}
<|endoftext|>