	int result = 0;
	for (int i = 0; i < n; i += 2) {
		if (arr[i] % 2 == 0) {
			result += arr[i];
		}
	}
	return result;
}
int main() {
	vector<int> arr1 = {5, 6, 12, 1, 18, 8};
	vector<int> arr2 = {3, 20, 17, 9, 2, 10, 18, 13, 6, 18};
	vector<int> arr3 = {5, 6, 12, 1};
	cout << sumEvenAndEvenIndex(arr1, 6) << endl;
	cout << sumEvenAndEvenIndex(arr2, 10) << endl;
	cout << sumEvenAndEvenIndex(arr3, 4) << endl;
	return 0;
}
<|endoftext|>