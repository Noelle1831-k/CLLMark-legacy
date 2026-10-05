	map<int, int> frequencyMap;
	map<int, int>::iterator itr;
	for (int i = 0; i < n; i++) {
		itr = frequencyMap.find(arr[i]);
		if (itr != frequencyMap.end()) {
			itr->second++;
		}
		else {
			frequencyMap.insert(pair<int, int>(arr[i], 1));
		}
	}
	itr = frequencyMap.begin();
	int highestFrequency = itr->second;
	itr++;
	while (itr != frequencyMap.end()) {
		if (itr->second > highestFrequency) {
			highestFrequency = itr->second;
		}
		itr++;
	}
	itr = frequencyMap.begin();
	int lowestFrequency = itr->second;
	itr++;
	while (itr != frequencyMap.end()) {
		if (itr->second < lowestFrequency) {
			lowestFrequency = itr->second;
		}
		itr++;
	}
	return highestFrequency - lowestFrequency;
}
int main() {
	cout << findDiff({ 1, 1, 2, 2, 7, 8, 4, 5, 1, 4 }, 10) << endl;
	cout << findDiff({ 1, 7, 9, 2, 3, 3, 1, 3, 3 }, 9) << endl;
	cout << findDiff({ 1, 2, 1, 2 }, 4) << endl;
	return 0;
}
<|endoftext|>