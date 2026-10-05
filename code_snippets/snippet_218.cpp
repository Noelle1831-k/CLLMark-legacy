	int result = 0;
	while (n != 0) {
		result |= (n & 1) << 1;
		n >>= 1;
	}
	return result;
}
int main() {
	cout << evenBitSetNumber(10) << endl;
	cout << evenBitSetNumber(20) << endl;
	cout << evenBitSetNumber(30) << endl;
	return 0;
}
<|endoftext|>