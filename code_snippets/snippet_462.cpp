	int count = 0;
	map<int, int> m;
	for(int i = 0; i < n; i++) {
		m[arr[i]]++;
	}
	for(int i = 0; i < n; i++) {
		if(m.count(sum - arr[i]) > 0 && (arr[i] != sum - arr[i] || m[arr[i]] > 1)) {
			count++;
		}
	}
	return count;
}
int main() {
	vector<int> arr1 = {1, 5, 7, -1, 5};
	int n1 = arr1.size();
	int sum1 = 6;
	cout << getPairsCount(arr1, n1, sum1) << endl;
	vector<int> arr2 = {1, 5, 7, -1};
	int n2 = arr2.size();
	int sum2 = 4;
	cout << getPairsCount(arr2, n2, sum2) << endl;
	vector<int> arr3 = {1, 1, 1, 1};
	int n3 = arr3.size();
	int sum3 = 2;
	cout << getPairsCount(arr3, n3, sum3) << endl;
	return 0;
}
<|endoftext|>