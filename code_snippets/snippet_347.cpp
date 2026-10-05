	if (n <= 0)
		return 0;
	while (n % 2 == 0)
		n /= 2;
	return 1 << (sizeof(int) * 8 - __builtin_clz(n) - 1);
}
int main() {
	std::cout << highestPowerOf2(10) << std::endl;
	std::cout << highestPowerOf2(19) << std::endl;
	std::cout << highestPowerOf2(32) << std::endl;
	return 0;
}
<|endoftext|>