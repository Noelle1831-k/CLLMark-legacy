	std::sort(nums.begin(), nums.end());
	for (int i = 0; i < nums.size(); ++i)
		if (nums[i] == nums[i+1])
			return nums[i];
	return -1;
}
int count(vector<int> nums, int target) {
	int count = 0;
	for (int i = 0; i < nums.size(); ++i)
		if (nums[i] == target)
			count++;
	return count;
}
int binarySearch(vector<int> nums, int target) {
	std::sort(nums.begin(), nums.end());
	int low = 0, high = nums.size() - 1;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (nums[mid] == target)
			return mid;
		else if (nums[mid] < target)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return -1;
}
int binarySearchRange(vector<int> nums, int target, int low, int high) {
	std::sort(nums.begin(), nums.end());
	while (low <= high) {
		int mid = (low + high) / 2;
		if (nums[mid] == target)
			return mid;
		else if (nums[mid] < target)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return -1;
}
/**
 * Write