	int size = x.size();
	if (size > 1) {
		int mid = size / 2;
		vector<int> l = mergeSort(vector<int>(x.begin(), x.begin() + mid));
		vector<int> r = mergeSort(vector<int>(x.begin() + mid, x.end()));
		vector<int> res;
		while (l.size() != 0 && r.size() != 0) {
			if (l[0] > r[0]) {
				res.push_back(r[0]);
				r.erase(r.begin());
			}
			else {
				res.push_back(l[0]);
				l.erase(l.begin());
			}
		}
		while (l.size() != 0) {
			res.push_back(l[0]);
			l.erase(l.begin());
		}
		while (r.size() != 0) {
			res.push_back(r[0]);
			r.erase(r.begin());
		}
		x = res;
	}
	return x;
}
int main() {
	vector<int> x = { 3, 4, 2, 6, 5, 7, 1, 9 };
	cout << mergeSort(x)[0] << ", " << mergeSort(x)[1] << ", " << mergeSort(x)[2] << ", " << mergeSort(x)[3] << ", " << mergeSort(x)[4] << ", " << mergeSort(x)[5] << ", " << mergeSort(x)[6] << ", " << mergeSort(x)[7] << ", " << endl;
	x = { 7, 25, 45, 78, 11, 33, 19 };
	cout << mergeSort(x)[0] << ", " << mergeSort(x)[1] << ", " << mergeSort(x)[2] << ", " << mergeSort(x)[3] << ", " << mergeSort(x)[4] << ", " << mergeSort(x)[5] << ", " << mergeSort(x)[6] << ", " << endl;
	x = { 3, 1, 4, 9, 8 };
	cout << mergeSort(x)[0] << ", " << mergeSort(x)[1] << ", " << mergeSort(x)[2] << ", " << mergeSort(x)[3] << ", " << mergeSort(x)[4] << ", " << endl;
	return 0;
}
<|endoftext|>