	int result = a;
	while (--n)
		result = a * result * r;
	return result;
}
int main() {
	printf("%d ", tnGp(1, 5, 2));
	printf("%d ", tnGp(1, 5, 4));
	printf("%d ", tnGp(2, 6, 3));
	return 0;
}
<|endoftext|>