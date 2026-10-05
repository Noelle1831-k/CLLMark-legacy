	int result = 0;
	while(n % 2 == 0) {
		n = n / 2;
		result += n;
	}
	for(int i = 3; i < sqrt(n); i += 2) {
		while(n % i == 0) {
			n = n / i;
			result += n;
		}
	}
	if(n > 2)
		result += n;
	return result;
}
<|endoftext|>