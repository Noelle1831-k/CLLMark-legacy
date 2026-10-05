	map<int, int> frequencyMap = {};
	for (int i = 0; i < n; i++) {
		if (frequencyMap.find(arr1[i]) == frequencyMap.end()) {
			frequencyMap[arr1[i]] = 1;
		} else {
			frequencyMap[arr1[i]]++;
		}
	}
	for (int i = 0; i < m; i++) {
		if (frequencyMap.find(arr2[i]) == frequencyMap.end()) {
			return false;
		} else {
			frequencyMap[arr2[i]]--;
			if (frequencyMap[arr2[i]] == 0) {
				frequencyMap.erase(arr2[i]);
			}
		}
	}
	return frequencyMap.empty();
}
int main() {
	cout << areEqual(vector<int>{1, 2, 3}, vector<int>{3, 2, 1}, 3, 3) << endl;
	cout << areEqual(vector<int>{1, 1, 1}, vector<int>{2, 2, 2}, 3, 3) << endl;
	cout << areEqual(vector<int>{8, 9}, vector<int>{4, 5, 6}, 2, 3) << endl;
	return 0;
}
<|endoftext|>