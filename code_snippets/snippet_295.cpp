	string pattern = "[a-zA-Z]{3,5}";
	std::regex r(pattern);
	std::smatch m;
	vector<string> res;
	while (std::regex_search(text, m, r)) {
		string match = m.str();
		res.push_back(match);
		text = m.suffix().str();
	}
	return res;
}
<|endoftext|>