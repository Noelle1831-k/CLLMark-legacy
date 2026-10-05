	while(y != 0) {
		y = y % x;
		n = n-1;
	}
	return n;
}
int main() {
	int n,x,y;
	cin >> n >> x >> y;
	cout << findMaxVal(n, x, y);
	return 0;
}
<|endoftext|>