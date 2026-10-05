	string text2;
	for (int i = 0; i < text.size(); i++) {
		if (text[i] == 'a') {
			while (i < text.size() && text[i] == 'a') {
				text2 += "a";
				i++;
			}
			while (i < text.size() && text[i] == 'b') {
				text2 += "b";
				i++;
			}
			if (i >= text.size()) {
				return "Found a match!";
			}
		}
	}
	return "Not matched!";
}
int main() {
	string text;
	while (getline(cin, text)) {
		cout << textMatch(text) << endl;
	}
	return 0;
}
<|endoftext|>