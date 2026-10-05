	string expression = "[A-Z]";
	string::iterator sub_start;
	string::iterator sub_end = find_if(text.begin(), text.end(), [=](int ch) {
		return isalpha(ch);
	});
	vector<string> words;
	while (sub_end != text.end()) {
		sub_start = sub_end;
		while (sub_start != text.end() && (sub_start == find_if(sub_start, text.end(), [=](int ch) {
			return isalpha(ch);
		}))) ++sub_start;
		string sub_str(sub_start, sub_end);
		sub_end = find_if(sub_end, text.end(), [=](int ch) {
			return !isalpha(ch);
		});
		sub_str = sub_str.substr(0, sub_str.length() - 1);
		words.push_back(sub_str);
	}
	return words;
}
int main() {
	string text, temp;
	while (1) {
		cout << "Enter a text: ";
		getline(cin, text);
		if (text == "")
			break;
		temp = "splitList(string(\"";
		temp += text;
		temp += "\"))";
		cout << temp << ": {";
		vector<string> words = splitList(text);
		for (int i = 0; i < words.size(); ++i) {
			temp = "\'" + words[i] + "\'";
			if (i < words.size() - 1)
				temp += ", ";
			cout << temp;
		}
		cout << "}" << endl;
	}
	return 0;
}
<|endoftext|>