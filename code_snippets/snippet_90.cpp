	unordered_map<int, int> frequencyMap;
	for (const auto &v : list1) {
		for (const auto &i : v) {
			frequencyMap[i] += 1;
		}
	}
	return frequencyMap;
}
int main() {
	vector<vector<int>> list1 = {
		{1, 2, 3, 2},
		{4, 5, 6, 2},
		{7, 8, 9, 5}
	};
	vector<vector<int>> list2 = {
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 10, 11, 12}
	};
	vector<vector<int>> list3 = {
		{20, 30, 40, 17},
		{18, 16, 14, 13},
		{10, 20, 30, 40}
	};
	unordered_map<int, int> frequencyMap = frequencyLists(list1);
	for (const auto &i : frequencyMap) {
		cout << "[" << i.first << ", " << i.second << "]" << ", ";
	}
	cout << endl;
	frequencyMap = frequencyLists(list2);
	for (const auto &i : frequencyMap) {
		cout << "[" << i.first << ", " << i.second << "]" << ", ";
	}
	cout << endl;
	frequencyMap = frequencyLists(list3);
	for (const auto &i : frequencyMap) {
		cout << "[" << i.first << ", " << i.second << "]" << ", ";
	}
	cout << endl;
	return 0;
}
<|endoftext|>