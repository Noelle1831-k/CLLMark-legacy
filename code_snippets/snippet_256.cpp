	std::sort(testList.begin(), testList.end());
	for (unsigned int i = 1; i < testList.size(); i++) {
		if (testList[i] == testList[i-1]) {
			return false;
		}
	}
	return true;
}
int longestIncreasingSubsequence(vector<int> testList) {
	std::sort(testList.begin(), testList.end());
	std::vector<int> lis(testList.size(), 1);
	std::vector<int> lds(testList.size(), 1);
	int longestLIS = 1;
	int longestLDS = 1;
	for (unsigned int i = 1; i < testList.size(); i++) {
		for (unsigned int j = 0; j < i; j++) {
			if (testList[i] > testList[j]) {
				lis[i] = std::max(lis[i], lis[j]+1);
				if (lis[i] > longestLIS) {
					longestLIS = lis[i];
				}
			}
		}
	}
	for (int i = testList.size()-2; i >= 0; i--) {
		for (int j = testList.size()-1; j > i; j--) {
			if (testList[i] > testList[j]) {
				lds[i] = std::max(lds[i], lds[j]+1);
				if (lds[i] > longestLDS) {
					longestLDS = lds[i];
				}
			}
		}
	}
	return longestLIS + longestLDS - 1;
}
int longestIncreasingSubsequenceConstantSpace(vector<int> testList) {
	std::vector<int> lis(testList.size(), 1);
	int longestLIS = 1;
	for (unsigned int i = 1; i < testList.size(); i++) {
		for (unsigned int j = 0; j < i; j++) {
			if (testList[i] > testList[j]) {
				lis[i] = std::max(lis[i], lis[j]+1);
				if (lis[i] > longestLIS) {
					longestLIS = lis[i];
				}
			}
		}
	}
	return longestLIS;
}
int longestDecreasingSubsequence(vector<int> testList) {
	std::sort(testList.begin(), testList.end());
	std::vector<int> lds(testList.size(), 1);
	int longestLDS = 1;
	for (int i = testList.size()-2; i >= 0; i--) {
		for (int j = testList.size()-1; j > i; j--) {
			if (testList[i] > testList[j]) {
				lds[i] = std::max(lds[i], lds[j]+1);
				if (lds[i] > longestLDS) {
					longestLDS = lds[i];
				}
			}
		}
	}
	return longestLDS;
}
int longestDecreasingSubsequenceConstantSpace(vector<int> testList) {
	std::vector<int> lds(testList.size(), 1);
	int longestLDS = 1;
	for (int i = testList.size()-2; i >= 0; i--) {
		for (int j = testList.size()-1; j > i; j--) {
			if (testList[i] > testList[j]) {
				lds[i] = std::max(lds[i], lds[j]+1);
				if (lds[i] > longestLDS) {
					longestLDS = lds[i];
				}
			}
		}
	}
	return longestLDS;
}
int longestIncreasingSubsequenceDP(vector<int> testList) {
	std::vector<int> lis(testList.size(), 1);
	int longestLIS = 1;
	for (unsigned int i = 1; i < testList.size(); i++) {
		for (unsigned int j = 0; j < i; j++) {
			if (testList[i] > testList[j]) {
				lis[i] = std::max(lis[i], lis[j]+1);
				if (lis[i] > longestLIS) {
					longestLIS = lis[i];
				}
			}
		}
	}
	return longestLIS;
}
int longestDecreasingSubsequenceDP(vector<int> testList) {
	std::vector<int> lds(testList.size(), 1);
	int longestLDS = 1;
	for (int i = testList.size()-2; i >= 0; i--) {
		for (int j = testList.size()-1; j > i; j--) {
			if (testList[i] > testList[j]) {
				lds[i] = std::