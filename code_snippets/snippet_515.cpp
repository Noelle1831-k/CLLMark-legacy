	int i,big,small;
	big=small=nums[0];
	for(i=1;i<nums.size();i++)
	{
		if(nums[i]>big)
		{
			big=nums[i];
		}
		else if(nums[i]<small)
		{
			small=nums[i];
		}
	}
	return big-small;
}
<|endoftext|>