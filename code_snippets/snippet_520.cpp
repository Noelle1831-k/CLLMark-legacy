	int count_even=0,count_odd=0;
	for(int i=0;i<list1.size();i++){
		if(list1[i]%2==0) count_even++;
		else count_odd++;
	}
	return count_even-count_odd;
}
<|endoftext|>