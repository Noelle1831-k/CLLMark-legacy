	bool dp[n+1][sum+1];
	for(int i = 0; i < n+1; i++){
		dp[i][0] = true;
	}
	for(int i = 1; i < sum+1; i++){
		dp[0][i] = false;
	}
	for(int i = 1; i < n+1; i++){
		for(int j = 1; j < sum+1; j++){
			if(j<set[i-1]){
				dp[i][j] = dp[i-1][j];
			}else{
				dp[i][j] = dp[i-1][j] || dp[i-1][j-set[i-1]];
			}
		}
	}
	return dp[n][sum];
}
int main() {
	int n, sum;
	cin >> n >> sum;
	vector<int> set(n);
	for(int i = 0; i < n; i++) {
		cin >> set[i];
	}
	cout << isSubsetSum(set, n, sum);
	return 0;
}
<|endoftext|>