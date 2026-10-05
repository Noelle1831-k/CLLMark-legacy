	unsigned int m = (~((1 << (r+1)) - 1)) - ((1 << l) - 1);
	unsigned int v = n & m;
	return v == 0;
}
int main() {
	cout << allBitsSetInTheGivenRange(4, 1, 2) << endl;
	cout << allBitsSetInTheGivenRange(17, 2, 4) << endl;
	cout << allBitsSetInTheGivenRange(39, 4, 6) << endl;
	return 0;
}
<|endoftext|>