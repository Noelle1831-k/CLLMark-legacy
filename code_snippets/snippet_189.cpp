	char sChar = c[0];
	int count = 0;
	for (char charS : s) {
		if (charS == sChar) {
			count++;
		}
	}
	return count;
}
int main() {
	string s = "abcc";
	string c = "c";
	cout << count(s, c);
	return 0;
}
<|endoftext|>