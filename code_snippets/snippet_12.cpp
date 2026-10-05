	std::sort(m.begin(), m.end(), [=](const vector<int>& v1, const vector<int>& v2) {
		return accumulate(v1.begin(), v1.end(), 0) < accumulate(v2.begin(), v2.end(), 0);
	});
	return m;
}
int main() {
	vector<vector<int>> v {{1, 2, 3}, {2, 4, 5}, {1, 1, 1}};
	std::cout << sortMatrix(v);
	return 0;
}
<|endoftext|>