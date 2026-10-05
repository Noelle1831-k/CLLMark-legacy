	int i = 1;
	while(sqrt(i) * sqrt(i) < n){
		while(sqrt(i) * sqrt(i) + sqrt(i+1) * sqrt(i+1) < n) i++;
		if(sqrt(i) * sqrt(i) == n) return true;
		i++;
	}
	return false;
}
<|endoftext|>