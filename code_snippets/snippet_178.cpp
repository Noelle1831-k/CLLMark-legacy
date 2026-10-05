	std::sort(testTup.begin(), testTup.end());
    auto new_end = std::unique(testTup.begin(), testTup.end());
    testTup.erase(new_end, testTup.end());
    return testTup;
}
int main() {
	std::cout << "Calling removeTuple(vector<int>{1, 3, 5, 2, 3, 5, 1, 1, 3})" << std::endl;
	std::cout << removeTuple(vector<int>{1, 3, 5, 2, 3, 5, 1, 1, 3}) << std::endl; 
	std::cout << "Calling removeTuple(vector<int>{2, 3, 4, 4, 5, 6, 6, 7, 8, 8})" << std::endl;
	std::cout << removeTuple(vector<int>{2, 3, 4, 4, 5, 6, 6, 7, 8, 8}) << std::endl; 
	std::cout << "Calling removeTuple(vector<int>{11, 12, 13, 11, 11, 12, 14, 13})" << std::endl;
	std::cout << removeTuple(vector<int>{11, 12, 13, 11, 11, 12, 14, 13}) << std::endl; 
	return 0;
}
<|endoftext|>