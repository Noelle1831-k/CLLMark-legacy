	int dp[str.size()+1][str.size()+1];
	for(int i = 0; i < str.size()+1; i++) {
		for(int j = 0; j < str.size()+1; j++) {
			if(i == 0 || j == 0) {
				dp[i][j] = 0;
			}
			else if(str[i-1] == str[j-1]) {
				dp[i][j] = 1 + dp[i-1][j-1];
			}
			else {
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}
	return dp[str.size()][str.size()];
}
int main()
{
	string str = "TENS FOR TENS";
	cout << "Length of lps is " << lps(str) << endl;
	str = "CARDIO FOR CARDS";
	cout << "Length of lps is " << lps(str) << endl;
	str = "PART OF THE JOURNEY IS PART";
	cout << "Length of lps is " << lps(str) << endl;
	return 0;
}
<|endoftext|>