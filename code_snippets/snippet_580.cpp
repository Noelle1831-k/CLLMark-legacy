	int count = 0;
	int sum = 0;
	while(n>0) {
		count++;
		sum+=n;
		n=n-2;
	}
	return sum/count;
}
<|endoftext|>