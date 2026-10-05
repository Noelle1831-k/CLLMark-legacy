	vector<int> dp(n, 1); 
	int dpsum = 0; 
	for(int i=1; i<n; i++) {
		for(int j=0; j<i; j++) {
			if(arr[j] < arr[i]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		dpsum += arr[i] * dp[i];
	}
	return dpsum;
}
int main() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i=0; i<n; i++) {
		cin >> arr[i];
	}
	cout << maxSumIncreasingSubsequence(arr, n) << endl;
	return 0;
}
<|endoftext|>