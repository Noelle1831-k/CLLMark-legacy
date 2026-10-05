	int sum = 0;
	for_each(nums.begin(), nums.end(), [sum](int i) {
		if (i > 0)
		{
			sum += i;
		}
	});
	return sum;
}
<|endoftext|>