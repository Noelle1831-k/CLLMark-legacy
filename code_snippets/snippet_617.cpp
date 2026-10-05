    unordered_set<int> s(arr1.begin(), arr1.end());
    unordered_set<int> res(arr2.begin(), arr2.end());
    return s.size() >= res.size() && s.size() <= m && all_of(res.begin(), res.end(), [s](int i) { return s.find(i) != s.end(); });
}
int main() {
	vector<int> arr1, arr2;
	int m, n;
	arr1 = {11, 1, 13, 21, 3, 7};
	m = 6;
	arr2 = {11, 3, 7, 1};
	n = 4;
	cout << isSubset(arr1, m, arr2, n) << endl;
	arr1 = {1, 2, 3, 4, 5, 6};
	m = 6;
	arr2 = {1, 2, 4};
	n = 3;
	cout << isSubset(arr1, m, arr2, n) << endl;
	arr1 = {10, 5, 2, 23, 19};
	m = 5;
	arr2 = {19, 5, 3};
	n = 3;
	cout << isSubset(arr1, m, arr2, n) << endl;
	return 0;
}
<|endoftext|>