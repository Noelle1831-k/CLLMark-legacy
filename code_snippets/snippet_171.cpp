	string matchPattern = "|";
	for (string &pattern : patterns) {
		matchPattern += pattern + "|";
	}
	matchPattern.pop_back();
	matchPattern = "(?=" + matchPattern + ")";
	string matchResult = regex_search(text, regex(matchPattern)) ? "Matched!" : "Not Matched!";
	return matchResult;
}
int main() {
	string text, pattern;
	while (cin >> text >> pattern) {
		vector<string> patterns;
		while (pattern != "") {
			patterns.push_back(pattern);
			cin >> pattern;
		}
		cout << checkLiterals(text, patterns) << endl;
	}
	return 0;
}
<|endoftext|>