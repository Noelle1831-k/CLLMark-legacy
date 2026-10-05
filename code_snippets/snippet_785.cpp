	if (n <= 3)
		return true;
	int i = 0, j = n - 1;
	while (i < j) {
		if (arr[i] > arr[j])
			return false;
		j--;
		i++;
	}
	return true;
}
int main() {
	vector<int> arr1 = { 3, 2, 1, 2, 3, 4 };
	vector<int> arr2 = { 2, 1, 4, 5, 1 };
	vector<int> arr3 = { 1, 2, 2, 1, 2, 3 };
	cout << check(arr1, 6) << endl;
	cout << check(arr2, 5) << endl;
	cout << check(arr3, 6) << endl;
	return 0;
}
<|endoftext|>