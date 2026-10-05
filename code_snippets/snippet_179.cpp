	int dec = 0, i = 0;
	while (n != 0) {
		dec += (n % 10) * pow(8, i);
		n /= 10;
		i++;
	}
	return dec;
}
<|endoftext|>