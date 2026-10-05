	map<int, int> myMap;
	int zero_count = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] == 0)
		{
			zero_count++;
		}
	}
	myMap[nums.size()] = zero_count;
	for (int i = 0; i < nums.size(); i++)
	{
		myMap[i] = zero_count;
	}
	for (int i = 0; i < nums.size(); i++)
	{
		myMap[nums.size()] -= myMap[i];
	}
	myMap[nums.size()] /= 2;
	myMap[nums.size()] /= 1.0;
	myMap[nums.size()] /= nums.size();
	return myMap[nums.size()];
}
<|endoftext|>