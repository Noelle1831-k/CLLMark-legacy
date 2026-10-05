	auto f = [&](int i){ return m%i==0 && n%i==0; };
	return vector<int>(std::find_if(nums.begin(), nums.end(), f), nums.end());
}
int main() {
	vector<int> nums = {19, 65, 57, 39, 152, 639, 121, 44, 90, 190};
	vector<int> res = divOfNums(nums, 2, 4);
	cout << "[ ";
	for (int i = 0; i < res.size(); i++) {
		cout << res[i];
		if (i != res.size() - 1)
		cout << ", ";
	}
	cout << " ]" << endl;
}
<|endoftext|>