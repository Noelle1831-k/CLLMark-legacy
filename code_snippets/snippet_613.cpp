	int i = 0;
	int sum = 0;
	int sum_l = 0;
	while (i < arr.size()) {
		sum += arr[i];
		i++;
	}
	i = 0;
	while (i < arr.size()) {
		sum -= arr[i];
		if (sum_l == sum) {
			return i;
		}
		sum_l += arr[i];
		i++;
	}
	return -1;
}
int main(int argc, const char** argv) {
    vector<int> arr1 = {1, 2, 3, 4, 1, 2, 3};
    vector<int> arr2 = {-7, 1, 5, 2, -4, 3, 0};
    vector<int> arr3 = {1, 2, 3};
    cout << equilibriumIndex(arr1) << endl;
    cout << equilibriumIndex(arr2) << endl;
    cout << equilibriumIndex(arr3) << endl;
    return 0;
}
<|endoftext|>