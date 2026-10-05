	int count = 0;
	int sum = 0;
	while(n>0){
		count++;
		if(n%2 != 0){
			sum+=n;
		}
		n--;
	}
	return sum/count;
}
<|endoftext|>