	return lst;
}
int main() {
	int n;
	cin >> n;
	vector<int> lst(n);
	for (int i = 0; i < n; i++) {
		cin >> lst[i];
	}
	vector<int> res = exchangeElements(lst);
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << " ";
	}
	cout << endl;
	return 0;
}
<|endoftext|>