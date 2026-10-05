	int result = testList[0][1] - testList[0][0];
	for (int i = 1; i < testList.size(); i++) {
		int currentResult = testList[i][1] - testList[i][0];
		if (currentResult > result) {
			result = currentResult;
		}
	}
	return result;
}
int main() {
	vector<vector<int>> testList{ { 3, 5 }, { 1, 7 }, { 10, 3 }, { 1, 2 } };
	cout << maxDifference(testList) << endl;
	testList = { { 4, 6 }, { 2, 17 }, { 9, 13 }, { 11, 12 } };
	cout << maxDifference(testList) << endl;
	testList = { { 12, 35 }, { 21, 27 }, { 13, 23 }, { 41, 22 } };
	cout << maxDifference(testList) << endl;
	return 0;
}<|endoftext|>