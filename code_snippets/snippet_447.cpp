	int count = 0;
	for (int i = 0; i < arr.size(); i++) {
		count += countNoOfSubsequences(arr, i, k);
	}
	return count;
}
int countNoOfSubsequences(vector<int> arr, int j, int k) {
	int count = 0;
	if (arr[j] > k)
		return 0;
	count += countNoOfSubsequences(arr, j + 1, k);
	count += countNoOfSubsequences(arr, j + 1, k / arr[j]);
	return count;
}
int main() {
	cout << noOfSubsequences({5, 6, 7, 8}, 15) << endl;
	return 0;
}
<|endoftext|>