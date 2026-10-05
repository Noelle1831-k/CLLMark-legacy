	unordered_set<int> res;
	for (auto it = testDict.begin(); it != testDict.end(); it++) {
		for (int i = 0; i < it->second.size(); i++) {
			res.insert(it->second[i]);
		}
	}
	vector<int> res_vec(res.begin(), res.end());
	return res_vec;
}
int main() {
	unordered_map<string, vector<int>> testDict{{string("msm"), {5, 6, 7, 8}}, {string("is"), {10, 11, 7, 5}}, {string("best"), {6, 12, 10, 8}}, {string("for"), {1, 2, 5}}};
	vector<int> res = extractUnique(testDict);
	cout << "[ ";
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << " ";
	}
	cout << "]" << endl;
}
<|endoftext|>