	testList.insert(testList.end(), testTup.begin(), testTup.end());
	return testList;
}
int main() {
	vector<int> testList{5, 6, 7};
	vector<int> testTup{9, 10};
	testList = addTuple(testList, testTup);
	testTup = {10, 11};
	testList = addTuple(testList, testTup);
	testTup = {11, 12};
	testList = addTuple(testList, testTup);
	for (auto it: testList)
		cout << it << " ";
	cout << endl;
	return 0;
}
<|endoftext|>