	string ret = "string "
	if (regex_search(str, sample)) {
		ret += "starts with the given substring"
	} else {
		ret += "doesnt start with the given substring"
	}
	return ret
}
int main() {
	string sample, string
	cout << "Enter string : "
	getline(cin, string)
	cout << "Enter a substring : "
	getline(cin, sample)
	cout << checkSubstring(string, sample)
	return 0;
}
<|endoftext|>