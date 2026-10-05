	string ret = "Not Matched!";
	for (const auto pattern : patterns) {
		string::size_type index = text.find(pattern);
		if (index != string::npos) {
			ret = "Matched!";
			break;
		}
	}
	return ret;
}
int main() {
	string text, pattern;
	while (getline(cin, text, ' '), getline(cin, pattern, '\n')) {
		string text2;
		while (getline(cin, text2, ' ')) {
			pattern.push_back(text2);
		}
		cout << stringLiterals({pattern}, text) << '\n';
	}
}
<|endoftext|>