	std::sort(testTup.begin(), testTup.end());
	vector<int> res;
	for (int i = 0; i < k; i++) {
		res.push_back(testTup[i]);
	}
	for (int i = testTup.size()-1; i >= testTup.size()-k; i--) {
		res.push_back(testTup[i]);
	}
	return res;
}
int main() {
	std::cout << "Maximum of first 3 values and minimum of last 3 values:\n";
	std::vector<int> testVec = {5, 20, 3, 7, 6, 8};
	std::vector<int> res = extractMinMax(testVec, 3);
	std::cout << "[ ";
	for (int i = 0; i < res.size(); i++) {
		std::cout << res[i] << " ";
	}
	std::cout << "]\n";
	return 0;
}
<|endoftext|>