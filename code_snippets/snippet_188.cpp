	unsigned diff = n1 ^ n2; 
	unsigned diff2 = diff; 
	while (diff2 != 0) {
		diff2 = diff2 & (diff2 - 1);
		count++;
	}
	return count;
}
<|endoftext|>