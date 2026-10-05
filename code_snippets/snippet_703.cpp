	for (int i = 0; i < testTup.size(); i++) {
		for (int j = 0; j < testTup.size(); j++) {
			if (i != j && (testTup[i] + testTup[j]) == k) {
				return true;
			}
		}
	}
	return false;
}
int main() {
	vector<int> testTup;
	int k;
	cin >> testTup[0] >> testTup[1] >> testTup[2] >> testTup[3] >> testTup[4] >> testTup[5];
	cin >> k;
	cout << checkK(testTup, k);
}
<|endoftext|>