	std::sort(nums.begin(), nums.end());
    auto lam = [] (int i) { return pow(i, 3); };
    transform(nums.begin(), nums.end(), nums.begin(), lam);
    return nums;
}
int main() {
	std::cout << "Hello World!" << std::endl;
	return 0;
}
<|endoftext|>