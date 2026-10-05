	int result = 0;
	for (int i = 0; i < nums.size(); i++) {
		while (nums[i] > 0) {
			result += nums[i] % 10;
			nums[i] /= 10;
		}
	}
	return result;
}
<|endoftext|>