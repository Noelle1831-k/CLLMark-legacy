	int i = 1, j = 1, k = 1;
	while(k < n) {
		k = k + j;
		j = j + i;
		i = k - j;
	}
	return k;
}
int main() {
	printf("Pell Number #%d: %d\n", 8, getPell(8));
	return 0;
}
<|endoftext|>