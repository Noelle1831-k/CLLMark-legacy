	int m = tri.size();
	vector<int> res(n);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (i > j) {
				res[j] = max(res[j], res[j - 1]) + tri[i][j];
			} else if (i == j) {
				res[j] = tri[i][j];
			} else {
				res[j] = max(res[j], res[j + 1]) + tri[i][j];
			}
		}
	}
	return res[0];
}
int main() {
	vector<vector<int>> tri {{1}, {2, 1}, {3, 3, 2}};
	int n = 3;
	cout << maxSum(tri, n) << endl;
	return 0;
}
<|endoftext|>