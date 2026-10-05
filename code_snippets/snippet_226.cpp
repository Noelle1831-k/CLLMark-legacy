	double root = 1;
	while(number != 0) {
		root = root + ((number / root) - root) / 2;
		number = number - (root * root);
	}
	return root;
}
int main() {
	int n;
	cin >> n;
	cout << babylonianSquareroot(n);
	return 0;
}
<|endoftext|>