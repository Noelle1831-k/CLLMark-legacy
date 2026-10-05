	int size = nums.size();
	int m = *max_element(nums.begin(), nums.end());
	while (m > 0) {
		int count[10] = {0};
		for (int i = 0; i < size; i++) {
			count[(nums[i] / m) % 10]++;
		}
		for (int i = 1; i < 10; i++) {
			count[i] += count[i - 1];
		}
		int tmp[size];
		for (int i = size - 1; i >= 0; i--) {
			tmp[count[(nums[i] / m) % 10] - 1] = nums[i];
			count[(nums[i] / m) % 10]--;
		}
		for (int i = 0; i < size; i++) {
			nums[i] = tmp[i];
		}
		m /= 10;
	}
	return nums;
}
<|endoftext|>