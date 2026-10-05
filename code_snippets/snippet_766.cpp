	string matchPattern = "a.*b";
	std::regex r(matchPattern);
	std::smatch m;
	std::regex_search(text, m, r);
	string matchResult = "Not matched!";
	if (m.size() > 0) {
		matchResult = "Found a match!";
	}
	return matchResult;
}
<|endoftext|>