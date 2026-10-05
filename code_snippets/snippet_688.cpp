	if (inputList.size() == 0)
		return 0;
	int count = 0;
	for (int i = 0; i < inputList.size(); i++) {
		count += inputList[i].size();
	}
	return count;
}
<|endoftext|>