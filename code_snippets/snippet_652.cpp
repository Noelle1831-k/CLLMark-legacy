	vector<vector<vector<int>>> lcs(m+1, vector<vector<int>>(n+1, vector<int>(o+1, 0)));
	for (int i = 0; i < m+1; i++) {
		for (int j = 0; j < n+1; j++) {
			for (int k = 0; k < o+1; k++) {
				if (i == 0 || j == 0 || k == 0)
					lcs[i][j][k] = 0;
				else if (x[i-1] == y[j-1] && y[j-1] == z[k-1])
					lcs[i][j][k] = 1 + lcs[i-1][j-1][k-1];
				else
					lcs[i][j][k] = max(lcs[i-1][j][k], max(lcs[i][j-1][k], lcs[i][j][k-1]));
			}
		}
	}
	return lcs[m][n][o];
}
int main()
{
	string X = "AGGT12";
	string Y = "12TXAYB";
	string Z = "12XBA";
	int m = 6, n = 7, o = 5;
	cout << lcsOfThree(X, Y, Z, m, n, o) << endl; 
	string X = "Reels";
	string Y = "Reelsfor";
	string Z = "ReelsforReels";
	int m = 5, n = 8, o = 13;
	cout << lcsOfThree(X, Y, Z, m, n, o) << endl; 
	string X = "abcd1e2";
	string Y = "bc12ea";
	string Z = "bd1ea";
	int m = 7, n = 6, o = 5;
	cout << lcsOfThree(X, Y, Z, m, n, o) << endl; 
	return 0;
}
<|endoftext|>