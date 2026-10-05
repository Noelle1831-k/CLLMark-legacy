	int sum = 0;
	for (int i = 0; i < arr.size(); i++) {
		sum += arr[i];
	}
	return sum;
}
int main() {
	vector<int> myVec{1, 2, 3};
	cout << Sum(myVec) << endl; 
	myVec = {15, 12, 13, 10};
	cout << Sum(myVec) << endl; 
	myVec = {0, 1, 2};
	cout << Sum(myVec) << endl; 
	return 0;
}
<|endoftext|>