	int i, j, k;
	int count1, count2;
	count1 = 0;
	count2 = 0;
	for (i = 0; i < n-1; i++) {
		for (j = i+1; j < n; j++) {
			if (a[i] > a[j])
				count1++;
		}
	}
	for (i = 0; i < n-1; i++) {
		for (j = i+1; j < n; j++) {
			if (a[i] > a[j])
				count2++;
		}
	}
	if (count1 == count2)
		return true;
	else
		return false;
}
int main() {
	#ifndef ONLINE_JUDGE 
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		cout << solve(a, n) << endl;
	}
	return 0;
}
<|endoftext|>