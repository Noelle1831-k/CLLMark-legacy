	std::sort(nums.begin(), nums.end(), std::greater<int>());
	std::for_each(nums.begin(), nums.end(), [=](int& num) {
		num *= num;
	});
	return nums;
}
int main() {
	std::cout << squareNums({1, 2, 3, 4, 5, 6, 7, 8, 9, 10}) << '\n';
	std::cout << squareNums({10, 20, 30}) << '\n';
	std::cout << squareNums({12, 15}) << '\n';
}
<|endoftext|>