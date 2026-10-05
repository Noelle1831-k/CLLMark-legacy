	vector<vector<int>> output;
	for (int i = 0; i < testTup1.size(); i++) {
		vector<int> row;
		for (int j = 0; j < testTup1[i].size(); j++) {
			row.push_back(testTup1[i][j] - testTup2[i][j]);
		}
		output.push_back(row);
	}
	return output;
}
vector<vector<int>> addElements(vector<vector<int>> testTup1, vector<vector<int>> testTup2) {
	vector<vector<int>> output;
	for (int i = 0; i < testTup1.size(); i++) {
		vector<int> row;
		for (int j = 0; j < testTup1[i].size(); j++) {
			row.push_back(testTup1[i][j] + testTup2[i][j]);
		}
		output.push_back(row);
	}
	return output;
}
vector<vector<int>> multiplyElements(vector<vector<int>> testTup1, vector<vector<int>> testTup2) {
	vector<vector<int>> output;
	for (int i = 0; i < testTup1.size(); i++) {
		vector<int> row;
		for (int j = 0; j < testTup1[i].size(); j++) {
			row.push_back(testTup1[i][j] * testTup2[i][j]);
		}
		output.push_back(row);
	}
	return output;
}
vector<vector<int>> divideElements(vector<vector<int>> testTup1, vector<vector<int>> testTup2) {
	vector<vector<int>> output;
	for (int i = 0; i < testTup1.size(); i++) {
		vector<int> row;
		for (int j = 0; j < testTup1[i].size(); j++) {
			row.push_back(testTup1[i][j] / testTup2[i][j]);
		}
		output.push_back(row);
	}
	return output;
}
/**
 * Write a function to count the sum of the given nested tuples.
 * > countSum(vector<vector<int>>{{1, 3}, {4, 5}, {2, 9}, {1, 10}})
 * 44
 * > countSum(vector<vector<int>>{{13, 4}, {14, 6}, {13, 10}, {12, 11