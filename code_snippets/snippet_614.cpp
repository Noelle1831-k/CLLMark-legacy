	int count = 0;
	for (int i = 0; i < n-1; i++) {
		count += (arr[i+1] - arr[i]) - 1;
		if (count > k) {
			count -= (arr[i+1] - arr[i]) - 1;
			count++;
			count += (arr[i+2] - arr[i+1]) - 1;
			break;
		}
	}
	return count;
}
int main() {
	vector<int> arr1 = {1, 3, 4, 9, 10, 11, 12, 17, 20};
	assert(removals(arr1, 9, 4) == 5);
	vector<int> arr2 = {1, 5, 6, 2, 8};
	assert(removals(arr2, 5, 2) == 3);
	vector<int> arr3 = {1, 2, 3, 4, 5, 6};
	assert(removals(arr3, 6, 3) == 2);
	return 0;
}
<|endoftext|>