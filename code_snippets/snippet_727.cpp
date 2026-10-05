	vector<vector<int>> ans(n, vector<int>(n, 0));
	int rowStart = 0, rowEnd = n - 1, colStart = 0, colEnd = n - 1, num = 1;
	while (rowStart <= rowEnd && colStart <= colEnd) {
		for (int i = colStart; i <= colEnd; i++) {
			ans[rowStart][i] = num++;
		}
		rowStart++;
		for (int i = rowStart; i <= rowEnd; i++) {
			ans[i][colEnd] = num++;
		}
		colEnd--;
		if (rowStart <= rowEnd) {
			for (int i = colEnd; i >= colStart; i--) {
				ans[rowEnd][i] = num++;
			}
			rowEnd--;
		}
		if (colStart <= colEnd) {
			for (int i = rowEnd; i >= rowStart; i--) {
				ans[i][colStart] = num++;
			}
			colStart++;
		}
	}
	return ans;
}
int main() {
	for (auto x : generateMatrix(4)) {
		for (auto y : x) {
			cout << y << " ";
		}
		cout << "\n";
	}
	return 0;
}
<|endoftext|>