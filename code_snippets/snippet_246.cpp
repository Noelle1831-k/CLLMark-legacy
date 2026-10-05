	if (n <= 0)
		return 0;
	int result = 1;
	while (n != 1) {
		result += (1 << (n - 1));
		n -= 1;
	}
	return result;
}
int main() {
	cout << findStarNum(3) << endl;
	cout << findStarNum(4) << endl;
	cout << findStarNum(5) << endl;
	return 0;
}
<|endoftext|>