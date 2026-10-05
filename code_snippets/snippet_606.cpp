	vector<int> res{};
	for (int i = 0; i < nums.size() - 1; i++) {
		res.push_back(nums[i] * nums[i + 1]);
	}
	return res;
}
int main() {
	vector<int> input{4, 5, 8, 9, 6, 10};
	cout << mulConsecutiveNums(input) << endl;
	return 0;
}
<|endoftext|>