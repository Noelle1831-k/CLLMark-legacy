	vector<int> res;
	for (int i = 0; i < nums.size(); i++) {
		res.push_back(nums[i][n]);
	}
	return res;
}
int main() {
	vector<vector<int>> nums = {{1, 2, 3, 2}, {4, 5, 6, 2}, {7, 1, 9, 5}};
	printArr(specifiedElement(nums, 0));
	printArr(specifiedElement(nums, 2));
	printArr(specifiedElement(nums, 1));
}
<|endoftext|>