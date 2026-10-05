	if(n<1)
		return 1;
	int result = n%10;
	while(n>10){
		n /= 10;
		result = n%10;
	}
	return result;
}
<|endoftext|>