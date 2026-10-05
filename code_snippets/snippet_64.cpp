	string ret = "All tuples have same length";
	for (int i = 0; i < k; i++) {
		if (input[0].size() != input[i].size()) {
			ret = "All tuples do not have same length";
			break;
		}
	}
	return ret;
}
int main() {
	string ret;
	vector<vector<int>> input{ { 11, 22, 33 }, { 44, 55, 66 } };
	int k = 2;
	ret = getEqual(input, k);
	cout << ret << endl;
	return 0;
}
<|endoftext|>