	while(m > 1) {
		m--;
		for(int i = 0; i < n-1; i++) {
			tri[m][i] += max(tri[m-1][i], tri[m-1][i+1]);
		}
	}
	return tri[0][0];
}
int main() {
	vector<vector<int>> tri{{1, 0, 0}, {4, 8, 0}, {1, 5, 3}};
	printf("%dn", maxPathSum(tri, 3, 3));
	return 0;
}
<|endoftext|>