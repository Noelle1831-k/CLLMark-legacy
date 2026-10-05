	while (low < high) {
		int mid = low + (high - low) / 2;
		if (arr[mid] > arr[high]) low = mid + 1;
		else high = mid;
	}
	return arr[low];
}
int main() {
	vector<int> arr1 = { 1, 2, 3, 4, 5 };
	vector<int> arr2 = { 4, 6, 8 };
	vector<int> arr3 = { 2, 3, 5, 7, 9 };
	cout << findMin(arr1, 0, 4) << endl;
	cout << findMin(arr2, 0, 2) << endl;
	cout << findMin(arr3, 0, 4) << endl;
}
<|endoftext|>