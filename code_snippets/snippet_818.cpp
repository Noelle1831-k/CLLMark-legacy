	map<int, vector<vector<int>>> temp; 
	for (const auto &i : testList)
		temp[i[0]].push_back(i); 
	for (const auto &i : ordList)
		temp[i].swap(temp[i][0]); 
	testList.clear(); 
	for (const auto &i : temp)
		for (const auto &j : i.second)
			testList.push_back(j); 
	return testList;
}
int main() {
	vector<vector<int>> testList{ { 4, 3 }, { 1, 9 }, { 2, 10 }, { 3, 2 } };
	vector<int> ordList{ 1, 4, 2, 3 };
	testList = reArrangeTuples(testList, ordList);
	for (const auto &i : testList)
		cout << "[ ";
	for (const auto &i : testList)
		cout << "[ " << i[0] << ", " << i[1] << " ], ";
	for (const auto &i : testList)
		cout << "] ";
	cout << "\n";
}
<|endoftext|>