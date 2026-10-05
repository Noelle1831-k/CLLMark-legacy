	map<int, int> frequencyMap;
	map<int, int> frequencyMapRev;
	map<int, int> frequencyMapRev2; 
	string ret = "";
	for (vector<int> testVec : testList) {
		int firstInt = testVec[0];
		int secondInt = testVec[1];
		frequencyMap[firstInt] += 1;
		frequencyMap[secondInt] += 1;
		frequencyMapRev[secondInt] += 1;
		frequencyMapRev[firstInt] += 1;
		frequencyMapRev2[secondInt] += 1;
		frequencyMapRev2[firstInt] += 1;
		if (frequencyMap[firstInt] > 1) {
			ret += "1";
		} else {
			ret += "0";
		}
	}
	cout << frequencyMapRev << endl; 
	map<int, int>::iterator itr;
	for (itr = frequencyMapRev.begin(); itr != frequencyMapRev.end(); ++itr) {
		if (itr->second > 1) {
			ret += "1";
		} else {
			ret += "0";
		}
	}
	return ret;
}
int main() {
	vector<vector<int>> testList{ {5, 6}, {1, 2}, {6, 5}, {9, 1}, {6, 5}, {2, 1} };
	string ret = countBidirectional(testList);
	cout << ret << endl;
}
<|endoftext|>