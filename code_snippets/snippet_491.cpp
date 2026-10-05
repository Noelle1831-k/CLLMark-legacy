	std::sort(testTup1.begin(), testTup1.end());
	std::sort(testTup2.begin(), testTup2.end());
	std::merge(testTup1.begin(), testTup1.end(), testTup2.begin(), testTup2.end(), std::back_inserter(testTup1));
	std::sort(testTup1.begin(), testTup1.end());
	testTup1.erase(std::unique(testTup1.begin(), testTup1.end()), testTup1.end());
	return testTup1;
}
int main(int argc, char** argv) {
	std::cout << unionElements({3, 4, 5, 6}, {5, 7, 4, 10}) << std::endl;
	std::cout << unionElements({1, 2, 3, 4}, {3, 4, 5, 6}) << std::endl;
	std::cout << unionElements({11, 12, 13, 14}, {13, 15, 16, 17}) << std::endl;
	return 0;
}
<|endoftext|>