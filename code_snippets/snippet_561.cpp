	vector<int> res;
	k = k>input.size()?input.size():k;
	for(int i=0;i<k;i++){
		res.push_back(input[input.size()-1-i]);
	}
	return res;
}
int main() {
	int n;
	cin >> n;
	vector<int> input(n);
	for (int i = 0; i < n; i++) {
		cin >> input[i];
	}
	int k;
	cin >> k;
	vector<int> res = reverseArrayUptoK(input, k);
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << " ";
	}
	return 0;
}
<|endoftext|>