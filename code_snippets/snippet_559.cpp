	int i = 1, nonagonals = 1;
	while(i<=n){
		nonagonals += (i*i - i)/2;
		i++;
	}
	return nonagonals;
}
<|endoftext|>