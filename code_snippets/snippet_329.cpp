	vector<vector<int>> ans;
	while (n) {
		ans.push_back(testTup);
		n--;
	}
	return ans;
}
bool isIncreasingOrder(vector<int> testArr) {
	for (int i = 0; i < testArr.size() - 1; i++) {
		if (testArr[i] > testArr[i + 1]) {
			return false;
		}
	}
	return true;
}
bool isIncreasingOrder2(vector<int> testArr, int currPos) {
	if (currPos >= testArr.size() - 1) {
		return true;
	}
	if (testArr[currPos] > testArr[currPos + 1]) {
		return false;
	}
	return isIncreasingOrder2(testArr, currPos + 1);
}
unordered_map<string, int> countWords(string testStr) {
	unordered_map<string, int> ans;
	string currWord;
	for (int i = 0; i < testStr.size(); i++) {
		if (testStr[i] == ' ') {
			currWord += testStr[i];
			ans[currWord]++;
			currWord = "";
		} else {
			currWord += testStr[i];
		}
	}
	currWord += testStr[testStr.size() - 1];
	ans[currWord]++;
	return ans;
}
unordered_map<string, int> countWords2(string testStr, string currWord, int currPos) {
	unordered_map<string, int> ans;
	if (currPos >= testStr.size()) {
		ans[currWord]++;
		return ans;
	}
	if (testStr[currPos] == ' ') {
		countWords2(testStr, currWord + ' ', currPos + 1);
	} else {
		countWords2(testStr, currWord + testStr[currPos], currPos + 1);
	}
	ans[currWord]++;
	return ans;
}
unordered_map<string, int> countWords3(string testStr) {
	unordered_map<string, int> ans;
	string currWord;
	for (int i = 0; i < testStr.size(); i++) {
		if (testStr[i] == ' ') {
			currWord += testStr[i];
			ans[currWord]++;
			currWord = "";
		} else {
			currWord += testStr[i];
		}
	}
	currWord += testStr[testStr.size() - 1];
	ans[currWord]++;
	return ans;
}
unordered_map<string, int> countWords4(string testStr, string currWord, int currPos) {
	unordered_map<string, int> ans;
	if (currPos >= testStr.size()) {
		ans[currWord]++;
		return ans;
	}
	if (testStr[currPos] == ' ') {
		countWords4(testStr, currWord + ' ', currPos + 1);
	} else {
		countWords4(testStr, currWord + testStr[currPos], currPos + 1);
	}
	ans[currWord]++;
	return ans;
}
unordered_map<string, int> countWords5(string testStr) {
	unordered_map<string, int> ans;
	string currWord;
	for (int i = 0; i < testStr.size(); i++) {
		if (testStr[i] == ' ') {
			currWord += testStr[i];
			ans[currWord]++;
			currWord = "";
		} else {
			currWord += testStr[i];
		}
	}
	currWord += testStr[testStr.size() - 1];
	ans[currWord]++;
	return ans;
}
unordered_map<string, int> countWords6(string testStr, string currWord, int currPos) {
	unordered_map<string, int> ans;
	if (currPos >= testStr.size()) {
		ans[currWord]++;
		return ans;
	}
	if (testStr[currPos] == ' ') {
		countWords6(testStr, currWord + ' ', currPos + 1);
	} else {
		countWords6(testStr, currWord + testStr[currPos], currPos + 1);
	}
	ans[currWord]++;
	return ans;
}
unordered_map<string, int> countWords7(string testStr) {
	unordered_map<string, int> ans;
	string currWord;
	for (int i = 0; i < testStr.size(); i++) {
		if (testStr[i] == ' ') {
			currWord += testStr[i];
			ans[currWord]++;
			currWord = "";
		} else {
			currWord += testStr[i];
		}
	}
	currWord += testStr[testStr.size() - 1];
	ans[currWord]++;
	return ans;
}
unordered_map<string, int> countWords8(string testStr, string currWord, int currPos) {
	unordered_map<string, int> ans;
	if (currPos >= testStr.size()) {
		ans[currWord]++;
		return ans;
	}
	if (testStr[currPos] == ' ') {
		countWords8(testStr, currWord + ' ', currPos + 1);
	} else {
		countWords8(testStr, currWord + testStr[currPos], currPos + 1);
	}
	ans[currWord]++;
	return ans;
}
unordered_map<string, int> countWords9(string testStr) {
	unordered_map<string, int> ans;
	string currWord;
	for (int i = 0; i < testStr.size(); i++) {
		if (testStr[i] == ' ') {
			currWord += testStr[i];
			ans[currWord]++;
			currWord = "";
		} else {
			currWord += testStr[i];
		}
	}
	currWord += testStr[testStr.size() - 1];
	ans[currWord]++;
	return ans;
}
unordered_map<string, int> countWords10(