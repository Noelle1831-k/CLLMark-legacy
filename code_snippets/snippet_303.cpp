	if (x > y)
		return findDivisor(y, x);
	if (x == y)
		return x;
	if (x > 1) {
		while (y % x != 0)
			x--;
		return x;
	}
	else {
		while (y % 2 != 0)
			y--;
		return 2;
	}
}
int main() {
	int x, y;
	cin >> x >> y;
	cout << findDivisor(x, y) << endl;
	return 0;
}
<|endoftext|>