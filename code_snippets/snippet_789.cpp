	unsigned int counter = 0;
	while (n) {
		counter += (n & 1);
		n >>= 1;
	}
	return counter;
}
int main() {
	countUnsetBits(4);
}
<|endoftext|>