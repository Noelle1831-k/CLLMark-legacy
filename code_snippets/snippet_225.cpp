	int dp[n] = {0};
	int result = arr[0];
	for(int i = 1; i < n; i++){
		dp[i] = max(arr[i], dp[i-1] + arr[i]);
		result = max(result, dp[i]);
	}
	return result;
}
int main() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cout << maxSum(arr, n) << endl;
	return 0;
}
<|endoftext|>