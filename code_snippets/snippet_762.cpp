	int result = testList[0][1] - testList[0][0];
	for (int i = 1; i < testList.size(); i++) {
		int currentResult = testList[i][1] - testList[i][0];
		if (currentResult < result) {
			result = currentResult;
		}
	}
	return result;
}
int main() {
	vector<vector<int>> list_1 {{3, 5}, {1, 7}, {10, 3}, {1, 2}};
	cout << "Result for list_1 is: " << minDifference(list_1) << endl;
	vector<vector<int>> list_2 {{4, 6}, {12, 8}, {11, 4}, {2, 13}};
	cout << "Result for list_2 is: " << minDifference(list_2) << endl;
	vector<vector<int>> list_3 {{5, 17}, {3, 9}, {12, 5}, {3, 24}};
	cout << "Result for list_3 is: " << minDifference(list_3) << endl;
	return 0;
}
<|endoftext|>