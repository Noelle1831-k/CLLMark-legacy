	vector<int> res;
	for (auto x : nums)
	{
		if (x % 2 == 0)
		{
			res.push_back(x);
		}
	}
	return res;
}
int main() {
	vector<int> nums = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	vector<int> res = filterEvennumbers(nums);
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << " ";
	}
	cout << endl;
}
<|endoftext|>