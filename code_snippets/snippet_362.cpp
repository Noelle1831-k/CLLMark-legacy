	vector<vector<int>> ans;
	priority_queue<pair<int, pair<int, int>>> pq; 
	for (int i = 0; i < nums1.size(); i++) {
		for (int j = 0; j < nums2.size(); j++) {
			pq.push({nums1[i] + nums2[j], {i, j}});
			if (pq.size() > k) pq.pop();
		}
	}
	while (pq.size()) {
		pair<int, pair<int, int>> t = pq.top();
		pq.pop();
		ans.push_back({nums1[t.second.first], nums2[t.second.second]});
	}
	return ans;
}
int main() {
	vector<int> nums1 = {1, 3, 7};
	vector<int> nums2 = {2, 4, 6};
	int k = 2;
	printKPairs(nums1, nums2, k);
	return 0;
}
<|endoftext|>