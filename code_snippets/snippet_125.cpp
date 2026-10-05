	string ret = "EVEN";
	for (int i = 0; i < p; i++) {
		if (arr[n - 1] % 2 == 0) ret = "ODD";
		else ret = "EVEN";
		n -= 1;
	}
	return ret;
}
int main() {
	vector<int> arr = {5, 7, 10};
	int n = 3, p = 1;
	string ret = checkLast(arr, n, p);
	cout << ret << endl;
	return 0;
}
<|endoftext|>