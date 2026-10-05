	for(int i=0;i<n;i++){
		if(arr[i]==i)
		return i;
	}
	return -1;
}
int main() {
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<int> arr(n);
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		cout << findFixedPoint(arr, n) << endl;
	}
	return 0;
}
<|endoftext|>