	std::sort(data.begin(), data.end());
	for (int i = 1; i < data.size(); i++) {
		if (data[i] == data[i - 1]) {
			return false;
		}
	}
	return true;
}
int main() {
	std::cout << "testDistinct(vector<int>{1, 5, 7, 9})" << ": " << testDistinct(vector<int>{1, 5, 7, 9}) << std::endl;
	std::cout << "testDistinct(vector<int>{2, 4, 5, 5, 7, 9})" << ": " << testDistinct(vector<int>{2, 4, 5, 5, 7, 9}) << std::endl;
	std::cout << "testDistinct(vector<int>{1, 2, 3})" << ": " << testDistinct(vector<int>{1, 2, 3}) << std::endl;
	return 0;
}
<|endoftext|>