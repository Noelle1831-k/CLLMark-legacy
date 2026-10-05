	vector<int> res;
	int i = 0;
	while (i < nums.size()) {
		while (i < nums.size() - 1 && nums[i] == nums[i + 1]) {
			i++;
		}
		res.push_back(nums[i]);
		i++;
	}
	return res;
}
int main() {
	vector<int> testNums;
	testNums.push_back(1);
	testNums.push_back(1);
	testNums.push_back(3);
	testNums.push_back(4);
	testNums.push_back(4);
	testNums.push_back(5);
	testNums.push_back(6);
	testNums.push_back(7);
	printVector(addConsecutiveNums(testNums));
	printVector(addConsecutiveNums({4, 5, 8, 9, 6, 10}));
	printVector(addConsecutiveNums({1, 2, 3, 4, 5, 6, 7, 8, 9, 10}));
}
<|endoftext|>