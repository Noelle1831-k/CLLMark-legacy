	int result = 1;
	for (int i = n-k+1; i <= n; i++) {
		result *= i;
	}
	for (int i = 1; i <= k; i++) {
		result /= i;
	}
	return result;
}
int main() {
	int result = permutationCoefficient(10, 2);
	std::cout << result << std::endl;
	return 0;
}
<|endoftext|>