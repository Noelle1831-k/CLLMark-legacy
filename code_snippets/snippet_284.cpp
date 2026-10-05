	string pattern = r"\b[a-zA-Z]{5}\b";
	regex rgx(pattern);
	sregex_iterator iter(text.begin(), text.end(), rgx);
	sregex_iterator end;
	vector<string> words;
	while (iter != end) {
		string match = (*iter)[0];
		words.push_back(match);
		iter++;
	}
	return words;
}
bool areAnagram(string string1, string string2) {
	map<char, int> charFreqs1;
	map<char, int> charFreqs2;
	for (char character : string1) {
		charFreqs1[character]++;
	}
	for (char character : string2) {
		charFreqs2[character]++;
	}
	return charFreqs1 == charFreqs2;
}
bool areAnagram(string string1, string string2) {
	map<char, int> charFreqs1;
	map<char, int> charFreqs2;
	for (char character : string1) {
		charFreqs1[character]++;
	}
	for (char character : string2) {
		charFreqs2[character]++;
	}
	map<char, int>::iterator iter1 = charFreqs1.begin();
	map<char, int>::iterator iter2 = charFreqs2.begin();
	while (iter1 != charFreqs1.end()) {
		char character = (*iter1).first;
		int count = (*iter1).second;
		if (charFreqs2.count(character) == 0) {
			return false;
		}
		int count2 = (*iter2).second;
		if (count2 != count) {
			return false;
		}
		iter1++;
		iter2++;
	}
	return true;
}
bool areAnagram(string string1, string string2) {
	map<char, int> charFreqs1;
	map<char, int> charFreqs2;
	for (char character : string1) {
		charFreqs1[character]++;
	}
	for (char character : string2) {
		charFreqs2[character]++;
	}
	map<char, int>::iterator iter1 = charFreqs1.begin();
	map<char, int>::iterator iter2 = charFreqs2.begin();
	while (iter1 != charFreqs1.end()) {
		char character = (*iter1).first;
		int count = (*iter1).second;
		if (charFreqs2.count(character) == 0) {
			return false;
		}
		int count2 = (*iter2).second;
		if (count2 != count) {
			return false;
		}
		iter1++;
		iter2++;
	}
	return true;
}
bool areAnagram(string string1, string string2) {
	map<char, int> charFreqs1;
	map<char, int> charFreqs2;
	for (char character : string1) {
		charFreqs1[character]++;
	}
	for (char character : string2) {
		charFreqs2[character]++;
	}
	map<char, int>::iterator iter1 = charFreqs1.begin();
	map<char, int>::iterator iter2 = charFreqs2.begin();
	while (iter1 != charFreqs1.end()) {
		char character = (*iter1).first;
		int count = (*iter1).second;
		if (charFreqs2.count(character) == 0) {
			return false;
		}
		int count2 = (*iter2).second;
		if (count2 != count) {
			return false;
		}
		iter1++;
		iter2++;
	}
	return true;
}
bool areAnagram(string string1, string string2) {
	map<char, int> charFreqs1;
	map<char, int> charFreqs2;
	for (char character : string1) {
		charFreqs1[character]++;
	}
	for (char character : string2) {
		charFreqs2[character]++;
	}
	map<char, int>::iterator iter1 = charFreqs1.begin();
	map<char, int>::iterator iter2 = charFreqs2.begin();
	while (iter1 != charFreqs1.end()) {
		char character = (*iter1).first;
		int count = (*iter1).second;
		if (charFreqs2.count(character) == 0) {
			return false;
		}
		int count2 = (*iter2).second;
		if (count2 != count) {
			return false;
		}
		iter1++;
		iter2++;
	}
	return true;
}
bool areAnagram(string string1, string string2) {
	map<char, int> charFreqs1;
	map<char, int> charFreqs2;
	for (char character : string1) {
		charFreqs1[character]++;
	}
	for (char character : string2) {
		charFreqs2[character]++;
	}
	map<char, int>::iterator iter1 = charFreqs1.begin();
	map<char, int>::iterator iter2 = charFreqs2.begin();
	while (iter1 != charFreqs1.end()) {
		char character = (*iter1).first;
		int count = (*iter1).second;
		if (charFreqs2.count(character) == 0) {
			return false;
		}
		int count2 = (*iter2).second;
		if (count2 != count) {
			return false;
		}
		iter1++;
		iter2++;
	}
	return true;
}
bool areAnagram(string string1, string string2) {
	map<char, int> charFreqs1;
	map<char, int> charFreqs2;
	for (char character : string1) {
		charFreqs1[character]++;
	}
	for (char character : string2) {
		charFreqs2[character]++;
	}
	map<char, int>::iterator iter1 = charFreqs1.begin();
	map<char, int>::iterator iter2 = charFreqs2.begin();
