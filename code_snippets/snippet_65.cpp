	int N = nums.size();
	int gap = N; 
	while (gap > 1) {
		gap = int(gap * 10 / 13);
		if (gap < 1) {
			gap = 1;
		}
		for (int i = 0; i + gap < N; i++) {
			if (nums[i] > nums[i + gap]) {
				nums[i] = nums[i] ^ nums[i + gap];
				nums[i + gap] = nums[i] ^ nums[i + gap];
				nums[i] = nums[i] ^ nums[i + gap];
			}
		}
	}
	return nums;
}
int main() {
	std::vector<int> A{41, 32, 15, 19, 22};
	std::vector<int> B{5, 15, 37, 25, 79};
	std::vector<int> C{99, 15, 13, 47};
	std::vector<int> res_a = combSort(A);
	std::vector<int> res_b = combSort(B);
	std::vector<int> res_c = combSort(C);
	std::cout << (res_a == std::vector<int>{15, 19, 22, 32, 41}) << std::endl;
	std::cout << (res_b == std::vector<int>{5, 15, 25, 37, 79}) << std::endl;
	std::cout << (res_c == std::vector<int>{13, 15, 47, 99}) << std::endl;
	return 0;
}
<|endoftext|>