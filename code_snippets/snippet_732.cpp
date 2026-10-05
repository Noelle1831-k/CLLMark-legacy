	int count = 0;
	for(int i = 0; i < n-1; i++){
		for(int j = i+1; j < n; j++){
			if(arr[i] > arr[j]){
				count++;
			}
		}
	}
	return count;
}
int main() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cout << getInvCount(arr, n) << endl;
	return 0;
}
<|endoftext|>