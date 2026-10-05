	return ((x - y) ^ ((x - y) >> 31)) + y;
}
int main() {
	printf("%d\n", minOfTwo(10, 20));
	printf("%d\n", minOfTwo(19, 15));
	printf("%d\n", minOfTwo(-10, -20));
	return 0;
}
<|endoftext|>