	std::sort(testTup.begin(), testTup.end());
	for (int i = 0; i < testTup.size() - 1; i++) {
		if (testTup[i] == testTup[i + 1]) {
			return false;
		}
	}
	return true;
}
int main() {
	std::cout << "Check if test tuple is distinct" << std::endl;
	std::cout << (checkDistinct(vector<int>{1, 4, 5, 6, 1, 4}) ? "true" : "false") << std::endl;
	std::cout << (checkDistinct(vector<int>{1, 4, 5, 6}) ? "true" : "false") << std::endl;
	std::cout << (checkDistinct(vector<int>{2, 3, 4, 5, 6}) ? "true" : "false") << std::endl;
}
<|endoftext|>