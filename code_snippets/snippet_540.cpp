	std::sort(arr1.begin(), arr1.end());
	std::sort(arr2.begin(), arr2.end());
	std::vector<int> res;
	std::merge(arr1.begin(), arr1.end(), arr2.begin(), arr2.end(), std::back_inserter(res));
	std::cout << res << std::endl;
	std::cout << (double)res[res.size() / 2] << std::endl;
	std::cout << (double)res[(res.size() - 1) / 2] << std::endl;
	std::cout << (double)(res[res.size() / 2] + res[(res.size() - 1) / 2]) / 2 << std::endl;
	return (double)(res[res.size() / 2] + res[(res.size() - 1) / 2]) / 2;
}
int main() {
	std::cout << getMedian(std::vector<int>{3, 6, 14, 23, 36, 42}, std::vector<int>{2, 18, 27, 39, 49, 55}, 6) << std::endl;
	std::cout << getMedian(std::vector<int>{2, 4, 8, 9}, std::vector<int>{7, 13, 19, 28}, 4) << std::endl;
	std::cout << getMedian(std::vector<int>{1, 12, 15, 26, 38}, std::vector<int>{2, 13, 17, 30, 45}, 5) << std::endl;
	return 0;
}
<|endoftext|>