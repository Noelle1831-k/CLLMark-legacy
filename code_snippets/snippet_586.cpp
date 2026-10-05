	int i=1;
	while(i<nums.size()){
		if(nums[i]<nums[i-1])
		{
			return true;
		}
		i++;
	}
	return false;
}
<|endoftext|>