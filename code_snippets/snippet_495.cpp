	vector<string> words;
	string tmp="";
	for (const auto &i : word) {
		tmp+=i;
		words.push_back(tmp);
	}
	return words;
}
<|endoftext|>