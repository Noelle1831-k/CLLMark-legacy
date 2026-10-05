	int i,big,smol;
	big=nums[0];
	smol=nums[0];
	for(i=0;i<nums.size();i++)
	{
		if(big<nums[i])
		{
			big=nums[i];
		}
		if(smol>nums[i])
		{
			smol=nums[i];
		}
	}
	return big+smol;
}
<|endoftext|>