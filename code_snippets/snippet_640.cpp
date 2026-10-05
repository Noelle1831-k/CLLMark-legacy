	int result = 0;
	for(int i = 0; i < n; i++) {
		for(int j = i; j < n; j++) {
			int prod = 1;
			for(int k = i; k <= j; k++) {
				prod *= arr[k];
			}
			result += prod;
		}
	}
	return result;
}
int main() {
	cout << sumOfSubarrayProd(vector<int>{1, 2, 3}, 3) << endl;
	cout << sumOfSubarrayProd(vector<int>{1, 2}, 2) << endl;
	cout << sumOfSubarrayProd(vector<int>{1, 2, 3, 4}, 4) << endl;
	return 0;
}
<|endoftext|>