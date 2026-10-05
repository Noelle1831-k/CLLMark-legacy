	sort(arr.begin(), arr.end());
    int minimum = arr[1] - arr[0];
    for(int i = 1; i < n-1; i++){
        int difference = arr[i+1] - arr[i];
        if(difference < minimum){
            minimum = difference;
        }
    }
    return minimum;
}
int main() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cout << findMinDiff(arr, n);
	return 0;
}
<|endoftext|>