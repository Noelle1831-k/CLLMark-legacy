	int count_1=0;
	while(n>0){
		count_1=count_1+((n&1)*(n&1));
		n=n>>1;
	}
	return count_1;
}
<|endoftext|>