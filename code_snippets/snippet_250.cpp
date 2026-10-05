	vector<int> res;
	for (int i = 0; i < testTup1.size(); i++) {
		res.push_back(testTup1[i] - testTup2[i]);
	}
	return res;
}
int main() {
	vector<int> testTup1, testTup2;
	testTup1.push_back(10);
	testTup1.push_back(4);
	testTup1.push_back(5);
	testTup2.push_back(2);
	testTup2.push_back(5);
	testTup2.push_back(18);
	vector<int> res = substractElements(testTup1, testTup2);
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << " ";
	}
	cout << endl;
	return 0;
}
<|endoftext|>