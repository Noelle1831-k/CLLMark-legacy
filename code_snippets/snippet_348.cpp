	int f1 = 2, f2 = 1, temp;
	while (--n) {
		temp = f1 + f2;
		f1 = f2;
		f2 = temp;
	}
	return f2;
}
int main() {
	printf("%d", findLucas(4));
	return 0;
}
<|endoftext|>