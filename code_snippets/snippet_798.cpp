	char prev = s[0];
	for (int i = 1; i < s.length(); i++) {
		if (s[i] == prev) {
			return false;
		}
		prev = s[i];
	}
	return true;
}
int main() {
	string s = "abab";
	cout << isTwoAlter(s) << endl;
}
<|endoftext|>