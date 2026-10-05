	map<int, int> myMap;
	for (int i = 0; i < testTuple.size(); i++) {
		myMap[testTuple[i]]++;
	}
	for (int i = 0; i < k.size(); i++) {
		if (myMap[k[i]] > 1) {
			return false;
		}
	}
	return true;
}
int main() {
	vector<int> testTuple;
	testTuple.push_back(3);
	testTuple.push_back(5);
	testTuple.push_back(6);
	testTuple.push_back(5);
	testTuple.push_back(3);
	testTuple.push_back(6);
	vector<int> k;
	k.push_back(3);
	k.push_back(6);
	k.push_back(5);
	cout << checkTuples(testTuple, k) << endl;
}
<|endoftext|>