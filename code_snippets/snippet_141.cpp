	while(y != 0) {
		int z = x % y;
		x = y;
		y = z;
	}
	return x == 1;
}
int main() {
	return 0;
}
<|endoftext|>