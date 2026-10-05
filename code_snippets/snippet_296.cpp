	unsigned int m = n, c = 0;
	while (m) {
		m &= m - 1;
		c++;
	}
	return c;
}
int main() {
	countUnsetBits(4);
	return 0;
}
<|endoftext|>