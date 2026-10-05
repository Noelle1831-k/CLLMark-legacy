	map<int, int> m;
	map<int, int>::iterator it;
	vector<int> res;
	for (int i = 0; i < nums.size(); i++) {
		m[nums[i]]++;
	}
	for (it = m.begin(); it != m.end(); it++) {
		if (it->second == max(m.begin(), it, m.end())) {
			res.push_back(it->first);
		}
	}
	return res;
}
int main() {
	vector<int> nums = {2, 3, 8, 4, 7, 9, 8, 2, 6, 5, 1, 6, 1, 2, 3, 2, 4, 6, 9, 1, 2};
	vector<int> res = maxOccurrences(nums);
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << " ";
	}
	cout << endl;
	nums = {2, 3, 8, 4, 7, 9, 8, 7, 9, 15, 14, 10, 12, 13, 16, 16, 18};
	res = maxOccurrences(nums);
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << " ";
	}
	cout << endl;
	nums = {10, 20, 20, 30, 40, 90, 80, 50, 30, 20, 50, 10};
	res = maxOccurrences(nums);
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << " ";
	}
	cout << endl;
	return 0;
}
<|endoftext|>