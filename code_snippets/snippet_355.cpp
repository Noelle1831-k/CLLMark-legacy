	vector<int> res;
	for (int i = 0; i < testTup1.size(); i++) {
		res.push_back(testTup1[i] ^ testTup2[i]);
	}
	return res;
}
int main() {
	cout << bitwiseXor({10, 4, 6, 9}, {5, 2, 3, 3}) << endl;
	cout << bitwiseXor({11, 5, 7, 10}, {6, 3, 4, 4}) << endl;
	cout << bitwiseXor({12, 6, 8, 11}, {7, 4, 5, 6}) << endl;
	return 0;
}
<|endoftext|>