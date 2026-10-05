	unordered_map<int, int> res;
	for (const auto& num: nums) {
		for (const auto& x: num) {
			res[x] += 1;
		}
	}
	return res;
}
int main() {
	vector<vector<int>> nums = {{1, 2, 3, 2}, {4, 5, 6, 2}, {7, 1, 9, 5}};
	unordered_map<int, int> res = freqElement(nums);
	for (auto it: res) {
		cout << "[" << it.first << ", " << it.second << "]" << endl;
	}
	return 0;
}
<|endoftext|>