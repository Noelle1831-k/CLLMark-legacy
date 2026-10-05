	string matchPattern = "^(a|e|i|o|u)*\\w*";
	regex r(matchPattern);
	sregex_iterator iter(str.begin(), str.end(), r);
	sregex_iterator iter2;
	string ret = "Valid";
	for (auto it = iter; it != iter2; it++) {
		string match = it->str();
		if (match != str) ret = "Invalid";
	}
	return ret;
}
int main() {
	string str;
	cin >> str;
	cout << checkStr(str);
	return 0;
}
<|endoftext|>