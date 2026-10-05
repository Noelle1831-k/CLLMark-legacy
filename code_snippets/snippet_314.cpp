	map<char, int> charCount;
	for (int i = 0; i < s.size(); i++) {
		charCount[s[i]]++;
	}
	int count = 0;
	for (auto it = charCount.begin(); it != charCount.end(); it++) {
		count += it->second;
	}
	return count;
}
int main() {
	string s = "abcda";
	cout << minimumLength(s);
	return 0;
}
<|endoftext|>