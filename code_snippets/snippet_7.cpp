	string pattern = "[[:alpha:]]{4,}";
	std::regex rgx(pattern);
	std::smatch match;
	vector<string> words;
	while (std::regex_search(text, match, rgx)) {
		string match_text = match.str();
		words.push_back(match_text);
		text = match.suffix().str();
	}
	return words;
}
int main(int argc, char** argv)
{
	string text = "Please move back to stream";
	vector<string> words = findCharLong(text);
	for (string w : words)
		cout << w << ", ";
	cout << endl;
	return 0;
}
<|endoftext|>