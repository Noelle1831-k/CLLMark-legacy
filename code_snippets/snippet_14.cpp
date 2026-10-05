	string buffer = "";
	vector<string> words;
	for (const char& i : text) {
		if (i >= 'a' && i <= 'z') {
			buffer += i;
		}
		else {
			words.push_back(buffer);
			buffer = "";
		}
	}
	words.push_back(buffer);
	return words;
}
int main() {
	string text = "Programming";
	cout << "[" << text << "]" << endl;
	vector<string> words = splitLowerstring(text);
	for (const string& i : words) {
		cout << "[" << i << "]" << endl;
	}
}
<|endoftext|>