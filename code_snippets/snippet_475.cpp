	int count = 0;
	while(num1 > 0 || num2 > 0) {
		count++;
		num1 /= 10;
		num2 /= 10;
	}
	return count;
}
int main() {
	printf("%d\n", countDigits(9875, 10));
	printf("%d\n", countDigits((long long)98759853034, 100));
	printf("%d\n", countDigits(1234567, 500));
	return 0;
}
<|endoftext|>