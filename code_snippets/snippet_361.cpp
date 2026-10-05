	string even("Even Parity");
	string odd("Odd Parity");
	string ret = even; 
	while(x != 0) {
		if (x%2 != 0) {
			ret = odd;
		}
		x = x/2;
	}
	return ret;
}
<|endoftext|>