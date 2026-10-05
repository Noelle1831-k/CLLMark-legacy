	map<int, int> frequencyMap; 
	for (int i = 0; i < n; i++) {
		frequencyMap[arr[i]]++;
	}
	for (const auto [key, value] : frequencyMap) {
		if (value == k) {
			return key;
		}
	}
	return -1;
}
int main() {
	vector<int> arr1 = {0, 1, 2, 3, 4, 5};
	int result1 = firstElement(arr1, 6, 1);
	cout << result1 << endl;
	vector<int> arr2 = {1, 2, 1, 3, 4};
	int result2 = firstElement(arr2, 5, 2);
	cout << result2 << endl;
	vector<int> arr3 = {2, 3, 4, 3, 5, 7, 1, 2, 3, 5};
	int result3 = firstElement(arr3, 10, 2);
	cout << result3 << endl;
}
<|endoftext|>