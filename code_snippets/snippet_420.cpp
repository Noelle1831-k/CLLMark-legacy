	string pattern = "[A-Z][a-z]+";
	regex rgx(pattern);
	smatch res;
	if (regex_search(text, res, rgx)) {
		return "Yes";
	}
	return "No";
}
int main() {
	string text;
	std::getline(std::cin, text);
	std::cout << match(text) << std::endl;
	return 0;
}
<|endoftext|>