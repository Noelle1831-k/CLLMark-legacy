	map<int, int> cache; 
	cache[arr[0]] = 1; 
	int result = 1; 
	for (int i = 1; i < n; i++) {
		cache[arr[i]] = cache[arr[i-1]] + 1;
		result = max(result, cache[arr[i]]);
	}
	return result;
}
int main() {
	vector<int> arr1 = {2, 5, 6, 3, 7, 6, 5, 8};
	cout << maxLenSub(arr1, 8) << "\n";
	vector<int> arr2 = {-2, -1, 5, -1, 4, 0, 3};
	cout << maxLenSub(arr2, 7) << "\n";
	vector<int> arr3 = {9, 11, 13, 15, 18};
	cout << maxLenSub(arr3, 5) << "\n";
	return 0;
}
<|endoftext|>