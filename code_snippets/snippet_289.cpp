	vector<int> sums;
	int i = 0;
	while (i < testTuple.size()) {
		int firstElement = testTuple[i];
		int count = 1;
		while (i + 1 < testTuple.size() && testTuple[i + 1] == firstElement) {
			i++;
			count++;
		}
		sums.push_back(count * firstElement);
		i++;
	}
	return sums;
}
int main() {
	vector<int> testTuple;
	testTuple.push_back(5);
	testTuple.push_back(6);
	testTuple.push_back(3);
	testTuple.push_back(6);
	testTuple.push_back(10);
	testTuple.push_back(34);
	vector<int> sums = sumOfAlternates(testTuple);
	for (int i = 0; i < sums.size(); i++) {
		cout << sums[i] << ", ";
	}
	cout << endl;
}
<|endoftext|>