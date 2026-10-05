	while(y != 0) {
		int z = x % y;
		x = y;
		y = z;
	}
	return x;
}
<|endoftext|>