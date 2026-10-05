	map<string, int> frequencyMap; 
	for (int i = 0; i < testList.size(); i++) {
		string firstElement = to_string(testList[i][0]) + "," + to_string(testList[i][1]);
		string secondElement = to_string(testList[i][1]) + "," + to_string(testList[i][0]);
		string firstElementOpposite = to_string(testList[i][1]) + "," + to_string(testList[i][0]);
		string secondElementOpposite = to_string(testList[i][0]) + "," + to_string(testList[i][1]);
		if (frequencyMap.find(firstElement) != frequencyMap.end()) {
			frequencyMap[firstElement] += 1;
		} else if (frequencyMap.find(secondElement) != frequencyMap.end()) {
			frequencyMap[secondElement] += 1;
		} else if (frequencyMap.find(firstElementOpposite) != frequencyMap.end()) {
			frequencyMap[firstElementOpposite] += 1;
		} else if (frequencyMap.find(secondElementOpposite) != frequencyMap.end()) {
			frequencyMap[secondElementOpposite] += 1;
		} else {
			frequencyMap[firstElement] = 1;
		}
	}
	return frequencyMap.size();
}
int main() {
	vector<vector<int>> testList{ { 3, 4 }, { 1, 2 }, { 4, 3 }, { 5, 6 } };
	testList = { { 4, 15 }, { 2, 3 }, { 5, 4 }, { 6, 7 } };
	testList = { { 5, 16 }, { 2, 3 }, { 6, 5 }, { 6, 9 } };
	cout << extractFreq(testList);
	return 0;
}<|endoftext|>