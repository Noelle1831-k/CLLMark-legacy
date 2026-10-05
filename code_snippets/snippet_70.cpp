	int count = 0;
	if(m == 1 || n == 1)
		return 1;
	else {
		count = countSquares(m, n-1) + countSquares(m-1, n-1);
		return count;
	}
}
int main() {
	int m = 3, n = 4;
	cout << countSquares(m, n);
	return 0;
}
<|endoftext|>