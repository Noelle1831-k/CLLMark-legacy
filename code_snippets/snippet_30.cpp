	map<int, int> mymap;
	priority_queue<pair<int, int>> pq;
	for (const auto& num: nums) {
		for (const auto& i: num) {
			mymap[i]++;
		}
	}
	for (auto& i: mymap) {
		pq.push({i.second, i.first});
		if (pq.size() > k) {
			pq.pop();
		}
	}
	vector<int> res;
	while (!pq.empty()) {
		res.push_back(pq.top().second);
		pq.pop();
	}
	reverse(res.begin(), res.end());
	return res;
}
int main() {
	func({vector<int>{1, 2, 6}, {1, 3, 4, 5, 7, 8}, {1, 3, 5, 6, 8, 9}, {2, 5, 7, 11}, {1, 4, 7, 8, 12}}, 3);
	func({vector<int>{1, 2, 6}, {1, 3, 4, 5, 7, 8}, {1, 3, 5, 6, 8, 9}, {2, 5, 7, 11}, {1, 4, 7, 8, 12}}, 1);
	func({vector<int>{1, 2, 6}, {1, 3, 4, 5, 7, 8}, {1, 3, 5, 6, 8, 9}, {2, 5, 7, 11}, {1, 4, 7, 8, 12}}, 5);
	return 0;
}
<|endoftext|>