	vector<vector<int>> ret(tupleStr.size());
	for (unsigned i = 0; i < tupleStr.size(); ++i) {
		ret[i].push_back(stoi(tupleStr[i][0]));
		ret[i].push_back(stoi(tupleStr[i][1]));
	}
	return ret;
}
string longestWord(vector<string> words) {
	string ret = words[0];
	for (unsigned i = 1; i < words.size(); ++i) {
		if (words[i].size() > ret.size()) {
			ret = words[i];
		}
	}
	return ret;
}
string longestWord(vector<string> words) {
	string ret = words[0];
	for (unsigned i = 1; i < words.size(); ++i) {
		if (words[i].size() > ret.size()) {
			ret = words[i];
		}
	}
	return ret;
}
string longestWord(vector<string> words) {
	string ret = words[0];
	for (unsigned i = 1; i < words.size(); ++i) {
		if (words[i].size() > ret.size()) {
			ret = words[i];
		}
	}
	return ret;
}
string longestWord(vector<string> words) {
	string ret = words[0];
	for (unsigned i = 1; i < words.size(); ++i) {
		if (words[i].size() > ret.size()) {
			ret = words[i];
		}
	}
	return ret;
}
string longestWord(vector<string> words) {
	string ret = words[0];
	for (unsigned i = 1; i < words.size(); ++i) {
		if (words[i].size() > ret.size()) {
			ret = words[i];
		}
	}
	return ret;
}
string longestWord(vector<string> words) {
	string ret = words[0];
	for (unsigned i = 1; i < words.size(); ++i) {
		if (words[i].size() > ret.size()) {
			ret = words[i];
		}
	}
	return ret;
}
string longestWord(vector<string> words) {
	string ret = words[0];
	for (unsigned i = 1; i < words.size(); ++i) {
		if (words[i].size() > ret.size()) {
			ret = words[i];
		}
	}
	return ret;
}
string longestWord(vector<string> words) {
	string ret = words[0];
	for (unsigned i = 1; i < words.size(); ++i) {
		if (words[i].size() > ret.size()) {
			ret = words[i];
		}
	}
	return ret;
}
/**
 * Write a function to print the longest word in a list.
 * > longestWord(vector<string>{{string("a"), string("long"), string("word"), string("a")}})
 * word
 * > longestWord(vector<string>{{string("a"), string("a"), string("a"), string("