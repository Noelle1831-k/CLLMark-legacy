	vector<vector<int>> ans;
	for(int i=0; i<testTup1.size(); i++){
		vector<int> row;
		for(int j=0; j<testTup1[i].size(); j++){
			row.push_back(testTup1[i][j] + testTup2[i][j]);
		}
		ans.push_back(row);
	}
	return ans;
}
int main() {
	vector<vector<int>> testTup1 {{1, 3}, {4, 5}, {2, 9}, {1, 10}};
	vector<vector<int>> testTup2 {{6, 7}, {3, 9}, {1, 1}, {7, 3}};
	printTuples(addNestedTuples(testTup1, testTup2));
	testTup1 = {{2, 4}, {5, 6}, {3, 10}, {2, 11}};
	testTup2 = {{7, 8}, {4, 10}, {2, 2}, {8, 4}};
	printTuples(addNestedTuples(testTup1, testTup2));
	testTup1 = {{3, 5}, {6, 7}, {4, 11}, {3, 12}};
	testTup2 = {{8, 9}, {5, 11}, {3, 3}, {9, 5}};
	printTuples(addNestedTuples(testTup1, testTup2));
	return 0;
}
<|endoftext|>