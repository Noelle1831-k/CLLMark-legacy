	if (num==0)
		return 1;
	int result=0;
	for (int i=0;i<num;i++) {
		result += (catalanNumber(i)*catalanNumber(num-i-1));
	}
	return result;
}
<|endoftext|>