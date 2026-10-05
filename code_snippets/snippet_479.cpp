	int size = arr.size();
	if(size == 0){
		return 0;
	}
	vector<int> dp(size, 1);
	int max = 1;
	for(int i = 1; i < size; i++){
		for(int j = 0; j < i; j++){
			if(arr[i] > arr[j]){
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		max = max(max, dp[i]);
	}
	return max;
}
<|endoftext|>