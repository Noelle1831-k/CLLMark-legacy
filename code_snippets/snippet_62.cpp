	bool ascending = true;
	bool descending = true;
	for (int i = 0; i < a.size() - 1; i++) {
		if (a[i] > a[i + 1]) descending = false;
		if (a[i] < a[i + 1]) ascending = false;
	}
	return ascending or descending;
}
int main() {
	vector<int> input{1, 3, 2};
	cout << isMonotonic(input) << endl;
	return 0;
}
<|endoftext|>