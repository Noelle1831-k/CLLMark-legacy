	vector<int> res;
	for (int i = 0; i < testTup.size(); i++) {
		for (int j = i + 1; j < testTup.size(); j++) {
			if (testTup[i] > testTup[j]) {
				res.push_back(testTup[i]);
				res.push_back(testTup[j]);
			}
		}
	}
	return res;
}
int main() {
	vector<int> testTup = { 8, 9, 11, 14, 12, 13 };
	vector<int> res = inversionElements(testTup);
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << ", ";
	}
	return 0;
}
<|endoftext|>