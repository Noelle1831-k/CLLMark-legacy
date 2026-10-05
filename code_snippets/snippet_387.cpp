	unsigned pos_count = 0;
	unsigned size = nums.size();
	for (unsigned i = 0; i < size; i++) {
		if (nums[i] > 0)
			pos_count++;
	}
	return ((double)pos_count) / size;
}
int main() {
	std::cout << positiveCount(vector<int>{0, 1, 2, -1, -5, 6, 0, -3, -2, 3, 4, 6, 8}) << std::endl;
	std::cout << positiveCount(vector<int>{2, 1, 2, -1, -5, 6, 4, -3, -2, 3, 4, 6, 8}) << std::endl;
	std::cout << positiveCount(vector<int>{2, 4, -6, -9, 11, -12, 14, -5, 17}) << std::endl;
}
<|endoftext|>