	vector<int> res;
	for(int i=l1; i<=r1; i++) {
		if(find(l2, r2, i) == NULL) {
			res.push_back(i);
		}
	}
	return res;
}
int* find(int l, int r, int key) {
	while(l <= r) {
		int mid = l + (r-l)/2;
		if(mid == key) return key;
		else if(mid < key) l = mid + 1;
		else r = mid - 1;
	}
	return NULL;
}
int main() {
	int l1, r1, l2, r2;
	cin >> l1 >> r1 >> l2 >> r2;
	vector<int> res = findPoints(l1, r1, l2, r2);
	for(int i=0; i<res.size(); i++) {
		cout << res[i] << " ";
	}
	cout << endl;
	return 0;
}
<|endoftext|>