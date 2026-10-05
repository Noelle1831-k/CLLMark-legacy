	map<int, int> frequencyMap;
	map<int, int>::iterator itr;
	int result = 1;
	for (int i = 0; i < listData.size(); i++) {
		itr = frequencyMap.find(listData[i]);
		if (itr == frequencyMap.end()) {
			frequencyMap[listData[i]] = 1;
		} else {
			frequencyMap[listData[i]] += 1;
		}
	}
	for (itr = frequencyMap.begin(); itr != frequencyMap.end(); itr++) {
		if (itr->second == 1) {
			result *= itr->first;
		}
	}
	return result;
}
int main() {
	vector<int> inputList{7, 8, 9, 0, 1, 1};
	cout << uniqueProduct(inputList) << endl;
	return 0;
}
<|endoftext|>