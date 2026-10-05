	vector<vector<int>> outputList;
	for (int i = 0; i < testList.size(); i++) {
		for (int j = 0; j < testList.size(); j++) {
			if (i == j) {
				continue;
			}
			outputList.push_back({testList[i][0] + testList[j][0], testList[i][1] + testList[j][1]});
		}
	}
	return outputList;
}
int main() {
	vector<vector<int>> inputList{ {2, 4}, {6, 7}, {5, 1}, {6, 10} };
	vector<vector<int>> outputList = findCombinations(inputList);
	for (auto x : outputList) {
		cout << "[ ";
		for (int i = 0; i < x.size(); i++) {
			cout << x[i] << " ";
		}
		cout << "]" << endl;
	}
	return 0;
}
<|endoftext|>