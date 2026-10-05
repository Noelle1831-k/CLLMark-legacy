	int count = 0;
	string first = s.substr(0, 1);
	string last = s.substr(s.length() - 1, 1);
	string sub_first, sub_last;
	for (int i = 0; i < s.length(); i++) {
		sub_first = s.substr(i, 1);
		sub_last = s.substr(s.length() - i - 1, 1);
		if (sub_first == first && sub_last == last) count++;
	}
	return count;
}
int main() {
	string s = "abcab";
	cout << countSubstringWithEqualEnds(s);
	return 0;
}
<|endoftext|>