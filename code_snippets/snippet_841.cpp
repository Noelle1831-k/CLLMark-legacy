	string vowels = "aeiouAEIOU";
	for (int i = 0; i < str.length(); i++) {
		string::iterator iter = vowels.find(str[i]);
		if (iter != vowels.end()) {
			str[i] = '-';
		}
	}
	string::iterator iter = find(str.begin(), str.end(), '-');
	if (iter == str.end()) {
		return "accepted";
	} else {
		return "not accepted";
	}
}
int main() {
	string str("SEEquoiaL");
	cout << check(str) << endl;
	str = "program";
	cout << check(str) << endl;
	str = "fine";
	cout << check(str) << endl;
	return 0;
}
<|endoftext|>