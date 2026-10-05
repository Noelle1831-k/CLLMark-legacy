	vector<vector<int>> ans;
	for (int i = 0; i < testTup1.size(); i++) {
		vector<int> temp;
		for (int j = 0; j < testTup1[i].size(); j++) {
			temp.push_back(testTup1[i][j] * testTup2[i][j]);
		}
		ans.push_back(temp);
	}
	return ans;
}
int main() {
	vector<vector<int>> vect1, vect2;
	vect1.push_back({1, 3});
	vect1.push_back({4, 5});
	vect1.push_back({2, 9});
	vect1.push_back({1, 10});
	vect2.push_back({6, 7});
	vect2.push_back({3, 9});
	vect2.push_back({1, 1});
	vect2.push_back({7, 3});
	vector<vector<int>> ans = indexMultiplication(vect1, vect2);
	for (auto x : ans) {
		for (auto y : x) {
			cout << y << " ";
		}
		cout << endl;
	}
	return 0;
}
<|endoftext|>