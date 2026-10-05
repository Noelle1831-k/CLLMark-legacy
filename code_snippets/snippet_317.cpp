	list1.erase(std::remove_if(list1.begin(), list1.end(), [n](const vector<int> &v){return v.size() <= n;}), list1.end());
	list1.erase(std::remove_if(list1.begin(), list1.end(), [n](const vector<int> &v){return v[n] == 0;}), list1.end());
	return list1;
}
int main() {
	vector<vector<int>> list1 = {{1, 2, 3}, {2, 4, 5}, {1, 1, 1}};
	printMatrix(removeColumn(list1, 0));
	printMatrix(removeColumn(list1, 2));
	printMatrix(removeColumn(list1, 1));
	printMatrix(removeColumn(list1, 10));
	list1 = {{1, 3}, {5, 7}, {1, 3}, {13, 15, 17}, {5, 7}, {9, 11}};
	printMatrix(removeColumn(list1, 0));
	printMatrix(removeColumn(list1, 1));
	printMatrix(removeColumn(list1, 2));
	printMatrix(removeColumn(list1, 3));
	printMatrix(removeColumn(list1, 4));
	printMatrix(removeColumn(list1, 5));
	printMatrix(removeColumn(list1, 6));
	printMatrix(removeColumn(list1, 7));
	printMatrix(removeColumn(list1, 8));
	printMatrix(removeColumn(list1, 9));
	printMatrix(removeColumn(list1, 10));
	printMatrix(removeColumn(list1, 11));
}
<|endoftext|>