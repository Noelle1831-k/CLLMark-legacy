	numList.erase(remove_if(numList.begin(), numList.end(), [=](int i){ return i < 0; }), numList.end());
	return numList;
}
int main() {
	vector<int> testVec = {1, -2, 3, -4};
	testVec = removeNegs(testVec);
	cout << "testVec = ";
	for (int i = 0; i < testVec.size(); i++) {
		cout << testVec[i] << ", ";
	}
	cout << endl;
}
<|endoftext|>