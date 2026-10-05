	unordered_map<int, vector<int>> ans;
	for (auto x : testList) {
		if (ans.find(x[1]) == ans.end()) ans[x[1]] = {x[0]};
		else ans[x[1]].push_back(x[0]);
	}
	return ans;
}
int main() {
	vector<vector<int>> v = {{6, 5}, {2, 7}, {2, 5}, {8, 7}, {9, 8}, {3, 7}};
	unordered_map<int, vector<int>> ans = groupElement(v);
	for (auto x : ans) {
		cout << x.first << ": " << "[";
		for (auto y : x.second) cout << y << " ";
		cout << "]\n";
	}
	return 0;
}
<|endoftext|>