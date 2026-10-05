	int size = arr.size();
	if (size == 0)
		return 0;
	int result = 0;
	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j += 2) {
			for (int k = i; k < j; k++)
				result += arr[k];
		}
	}
	return result;
}
int main(int argc, char const *argv[]) {
	std::vector<int> input{1, 2, 4};
	std::cout << oddLengthSum(input) << std::endl;
	std::vector<int> input2{1, 2, 1, 2};
	std::cout << oddLengthSum(input2) << std::endl;
	std::vector<int> input3{1, 7};
	std::cout << oddLengthSum(input3) << std::endl;
	return 0;
}
<|endoftext|>