	int i = 0, j = n - 1;
	while (i < j) {
		while (arr[i] > 0 && i < j)
			i++;
		while (arr[j] < 0 && i < j)
			j--;
		if (i < j) {
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	return arr;
}
int main() {
	int n;
	cout << "Enter number of elements: ";
	cin >> n;
	vector<int> arr(n);
	cout << "Enter array elements: ";
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	vector<int> res = reArrangeArray(arr, n);
	cout << "Rearranged array is: ";
	for (int i = 0; i < n; i++) {
		cout << res[i] << " ";
	}
	cout << endl;
	return 0;
}
<|endoftext|>