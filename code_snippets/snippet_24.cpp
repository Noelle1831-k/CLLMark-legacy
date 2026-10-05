	map<int, int> mymap;
	int prod = 1;
	for(int i = 0; i < n; i++) {
		mymap[arr[i]]++;
	}
	for(auto it = mymap.begin(); it != mymap.end(); it++) {
		if(it->second == 1) prod *= it->first;
	}
	return prod;
}
int main() {
	vector<int> arr1 = {1, 1, 2, 3};
	vector<int> arr2 = {1, 2, 3, 1, 1};
	vector<int> arr3 = {1, 1, 4, 5, 6};
	int n1 = arr1.size();
	int n2 = arr2.size();
	int n3 = arr3.size();
	cout << "Product of the non-repeated elements of the given array is: " << findProduct(arr1, n1) << endl;
	cout << "Product of the non-repeated elements of the given array is: " << findProduct(arr2, n2) << endl;
	cout << "Product of the non-repeated elements of the given array is: " << findProduct(arr3, n3) << endl;
	return 0;
}
<|endoftext|>