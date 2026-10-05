	map<int, int> myMap;
	map<int, int>::iterator itr;
	map<int, int> myMap = transform(nums1.begin(), nums1.end(), nums2.begin(), nums1.begin(), std::minus<int>());
	vector<int> res;
	for (itr = myMap.begin(); itr != myMap.end(); ++itr)
	{
		res.push_back(itr->second);
	}
	return res;
}
int main(int argc, char** argv) {
	vector<int> nums1, nums2;
	nums1 = { 1, 2, 3 };
	nums2 = { 4, 5, 6 };
	cout << subList(nums1, nums2) << endl;
	nums1 = { 1, 2 };
	nums2 = { 3, 4 };
	cout << subList(nums1, nums2) << endl;
	nums1 = { 90, 120 };
	nums2 = { 50, 70 };
	cout << subList(nums1, nums2) << endl;
	return 0;
}
<|endoftext|>