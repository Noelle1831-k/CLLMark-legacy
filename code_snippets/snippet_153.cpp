	int count = 0;
	string alpha = "abcdefghijklmnopqrstuvwxyz";
	string alpha_up = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	for (int i = 0; i < str1.length(); i++) {
		if (str1[i] == alpha[i % 26] || str1[i] == alpha_up[i % 26]) {
			count++;
		}
	}
	return count;
}
int main() {
	string str("xbcefg");
	cout << countCharPosition(str);
	return 0;
}
<|endoftext|>