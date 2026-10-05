	int i = 0;
	int prod = 1;
	int result = arr[0];
	while (i < arr.size()) {
		prod *= arr[i];
		result = max(prod, result);
		if (prod == 0) prod = 1;
		i++;
	}
	prod = 1;
	i = arr.size() - 1;
	while (i >= 0) {
		prod *= arr[i];
		result = max(prod, result);
		if (prod == 0) prod = 1;
		i--;
	}
	return result;
}
int main() {
	vector<int> test = {-2, -40, 0, -2, -3};
	cout << maxSubarrayProduct(test) << endl; 
}
<|endoftext|>