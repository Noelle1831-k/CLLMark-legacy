	if (n <= 1)
		return 0;
	int i = 0, j = 0, k = 0, temp, prod = arr[0];
	while (i < n) {
		while (j < n) {
			if (arr[j] > arr[i]) {
				temp = arr[j];
				arr[j] = arr[i];
				arr[i] = temp;
			}
			j++;
		}
		prod *= arr[i];
		i++;
		j = i + 1;
	}
	return prod;
}
int main() {
	vector<int> arr1;
	arr1.push_back(3);
	arr1.push_back(100);
	arr1.push_back(4);
	arr1.push_back(5);
	arr1.push_back(150);
	arr1.push_back(6);
	cout << maxProduct(arr1, 6) << endl;
	vector<int> arr2;
	arr2.push_back(4);
	arr2.push_back(42);
	arr2.push_back(55);
	arr2.push_back(68);
	arr2.push_back(80);
	cout << maxProduct(arr2, 5) << endl;
	vector<int> arr3;
	arr3.push_back(10);
	arr3.push_back(22);
	arr3.push_back(9);
	arr3.push_back(33);
	arr3.push_back(21);
	arr3.push_back(50);
	arr3.push_back(41);
	arr3.push_back(60);
	cout << maxProduct(arr3, 8) << endl;
	return 0;
}
<|endoftext|>