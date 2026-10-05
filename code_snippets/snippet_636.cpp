	map<int, int> mymap;
	vector<int> res;
	for (int i = 0; i < nums1.size(); i++) {
		mymap[nums1[i]] = mymap[nums1[i]] + nums2[i];
	}
	for (auto it = mymap.begin(); it != mymap.end(); it++) {
		res.push_back(it->second);
	}
	return res;
}
int main() {
	vector<int> x = { 1, 2, 3 };
	vector<int> y = { 4, 5, 6 };
	vector<int> res = addList(x, y);
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << " ";
	}
	cout << endl;
	return 0;
}
<|endoftext|>