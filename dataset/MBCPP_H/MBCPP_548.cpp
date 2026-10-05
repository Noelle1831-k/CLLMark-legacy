	if (arr.size() == 0)
		return 0;
	int length = 1;
	int max = arr[0];
	int i;
	for (i = 0; i < arr.size(); i++)
	{
		if (arr[i] > max)
			length++;
			max = arr[i];
	}
	return length;
}