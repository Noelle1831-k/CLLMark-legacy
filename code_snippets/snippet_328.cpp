	int largestProduct = 0;
	for (int i = 0; i < listNums.size() - 1; i++) {
		largestProduct = max(largestProduct, listNums[i] * listNums[i + 1]);
	}
	return largestProduct;
}
int main() {
	vector<int> testVec = { 1, 2, 3, 4, 5, 6 };
	cout << adjacentNumProduct(testVec) << endl; 
	testVec = { 1, 2, 3, 4, 5 };
	cout << adjacentNumProduct(testVec) << endl; 
	testVec = { 2, 3 };
	cout << adjacentNumProduct(testVec) << endl; 
	return 0;
}
<|endoftext|>