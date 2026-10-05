	for (int i = 0; i < testTup1.size(); i++) {
		if (find(testTup2.begin(), testTup2.end(), testTup1[i]) == testTup2.end()) {
			return false;
		}
	}
	return true;
}
int main() {
	vector<int> testTup1;
	testTup1.push_back(10);
	testTup1.push_back(4);
	testTup1.push_back(5);
	testTup1.push_back(6);
	vector<int> testTup2;
	testTup2.push_back(5);
	testTup2.push_back(10);
	vector<int> testTup3;
	testTup3.push_back(7);
	testTup3.push_back(8);
	testTup3.push_back(9);
	testTup3.push_back(10);
	vector<int> testTup4;
	testTup4.push_back(7);
	testTup4.push_back(8);
	testTup4.push_back(9);
	assert(checkSubset(testTup1, testTup2) == true);
	assert(checkSubset(testTup3, testTup4) == false);
}
<|endoftext|>