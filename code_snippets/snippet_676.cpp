	map<char, int> charCount;
	charCount['a'] = 0;
	charCount['e'] = 0;
	charCount['i'] = 0;
	charCount['o'] = 0;
	charCount['u'] = 0;
	char prev = testStr[0];
	charCount[prev] += 1;
	int count = 1;
	for (int i = 1; i < testStr.length(); i++) {
		char curr = testStr[i];
		if (curr == prev) {
			count += 1;
		} else {
			charCount[prev] += count;
			count = 1;
		}
		prev = curr;
	}
	charCount[prev] += count;
	count = 0;
	for (auto it = charCount.begin(); it != charCount.end(); it++) {
		count += it->second;
	}
	return count;
}
bool allUniqueCharacters(string testStr) {
	map<char, int> charCount;
	for (int i = 0; i < testStr.length(); i++) {
		char curr = testStr[i];
		if (charCount.find(curr) != charCount.end()) {
			return false;
		}
		charCount[curr] = 1;
	}
	return true;
}
bool allUniqueCharacters2(string testStr) {
	string::iterator iter = testStr.begin();
	while (iter != testStr.end()) {
		char curr = *iter;
		string::iterator iter2 = testStr.begin();
		while (iter2 != testStr.end()) {
			if (curr == *iter2) {
				return false;
			}
			iter2++;
		}
		iter++;
	}
	return true;
}
bool allUniquePairs(vector<int> testVec) {
	map<int, int> intCount;
	for (int i = 0; i < testVec.size(); i++) {
		int curr = testVec[i];
		if (intCount.find(curr) != intCount.end()) {
			intCount[curr] += 1;
		} else {
			intCount[curr] = 1;
		}
	}
	for (auto it = intCount.begin(); it != intCount.end(); it++) {
		if (it->second > 1) {
			return false;
		}
	}
	return true;
}
bool allUniquePairs2(vector<int> testVec) {
	map<int, int> intCount;
	for (int i = 0; i < testVec.size(); i++) {
		int curr = testVec[i];
		if (intCount.find(curr) != intCount.end()) {
			return false;
		}
		intCount[curr] = 1;
	}
	return true;
}
bool allUniquePairs3(vector<int> testVec) {
	map<int, int> intCount;
	for (int i = 0; i < testVec.size(); i++) {
		int curr = testVec[i];
		if (intCount.find(curr) != intCount.end()) {
			return false;
		}
		intCount[curr] = testVec.size();
	}
	return true;
}
bool allUniquePairs4(vector<int> testVec) {
	map<int, int> intCount;
	for (int i = 0; i < testVec.size(); i++) {
		int curr = testVec[i];
		if (intCount.find(curr) != intCount.end()) {
			return false;
		}
		intCount[curr] = 1;
	}
	return true;
}
bool allUniquePairs5(vector<int> testVec) {
	map<int, int> intCount;
	for (int i = 0; i < testVec.size(); i++) {
		int curr = testVec[i];
		if (intCount.find(curr) != intCount.end()) {
			intCount[curr] += 1;
		} else {
			intCount[curr] = 1;
		}
	}
	for (auto it = intCount.begin(); it != intCount.end(); it++) {
		if (it->second > 1) {
			return false;
		}
	}
	return true;
}
/**
 * Return if all pairs of unique numbers exist that are equal.
 * > allUniquePairs6(vector<int>({3, 4, 8, 9, 1, 8, 8, 8}))
 * 0
 * > allUniquePairs6(vector<int>({3, 4, 8, 9, 