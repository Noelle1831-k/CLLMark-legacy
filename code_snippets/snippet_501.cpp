	vector<int> res;
	map<int, int> mymap;
	for (auto it: nums)
		mymap[it]++;
	for (auto it: mymap)
		if (it.second == 1)
			res.push_back(it.first);
	return res;
}
int main(int argc, char** argv) {
	vector<int> myVec{1, 2, 3, 2, 3, 4, 5};
	vector<int> res = twoUniqueNums(myVec);
	for (auto it: res)
		cout << it << ", ";
	return 0;
}
<|endoftext|>