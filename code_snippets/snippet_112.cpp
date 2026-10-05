	std::sort(list1.begin(), list1.end());
	int size = list1.size();
	int i, j, k;
	int result = 0;
	for (i = 0; i < size; i++) {
		for (j = i + 1; j < size; j++) {
			k = j + 1;
			while (k < size && list1[i][0] > list1[j][0] && list1[i][1] > list1[k][1]) {
				k++;
			}
			k--;
			if (k >= j) {
				result = max(result, (list1[i][0] * list1[j][1]) * list1[k][1]);
			}
		}
	}
	return result;
}
int main() {
	std::cout << maxProductTuple(vector<vector<int>>{{2, 7}, {2, 6}, {1, 8}, {4, 9}}) << std::endl;
	std::cout << maxProductTuple(vector<vector<int>>{{10, 20}, {15, 2}, {5, 10}}) << std::endl;
	std::cout << maxProductTuple(vector<vector<int>>{{11, 44}, {10, 15}, {20, 5}, {12, 9}}) << std::endl;
	return 0;
}
<|endoftext|>