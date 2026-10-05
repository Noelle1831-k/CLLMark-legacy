	int count = 0;
	map<int, int> frequencyMap;
	for (int i = 0; i < n; i++) {
		count += frequencyMap[arr[i]];
		frequencyMap[arr[i]]++;
	}
	return count;
}
int main() {
	int size;
	cout << "Enter array size : ";
	cin >> size;
	vector<int> arr(size);
	cout << "Enter array elements : ";
	for (int i = 0; i < size; i++) {
		cin >> arr[i];
	}
	cout << countPairs(arr, size);
	return 0;
}
<|endoftext|>