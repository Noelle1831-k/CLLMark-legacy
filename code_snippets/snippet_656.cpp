	if (i >= arr.size()) {
		return true;
	}
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	if (left < arr.size() && arr[i] > arr[left]) {
		return false;
	}
	if (right < arr.size() && arr[i] > arr[right]) {
		return false;
	}
	return checkMinHeap(arr, left) && checkMinHeap(arr, right);
}
int main() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cout << checkMinHeap(arr, 0) << endl;
	return 0;
}
<|endoftext|>