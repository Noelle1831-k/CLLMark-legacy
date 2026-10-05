	vector<vector<int>> ans;
	for (int i = 0; i < testTup1.size(); i++) {
		ans.push_back({testTup1[i], testTup2[i]});
	}
	return ans;
}
vector<vector<int>> zipTupler(vector<int> testTup1, vector<int> testTup2, vector<int> testTup3) {
	vector<vector<int>> ans;
	for (int i = 0; i < testTup1.size(); i++) {
		ans.push_back({testTup1[i], testTup2[i], testTup3[i]});
	}
	return ans;
}
vector<vector<int>> zipTupler(vector<int> testTup1, vector<int> testTup2, vector<int> testTup3, vector<int> testTup4) {
	vector<vector<int>> ans;
	for (int i = 0; i < testTup1.size(); i++) {
		ans.push_back({testTup1[i], testTup2[i], testTup3[i], testTup4[i]});
	}
	return ans;
}
vector<vector<int>> zipTupler(vector<int> testTup1, vector<int> testTup2, vector<int> testTup3, vector<int> testTup4, vector<int> testTup5) {
	vector<vector<int>> ans;
	for (int i = 0; i <