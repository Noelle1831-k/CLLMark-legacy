	int largest = 0;
	for (int i = 0; i < list1.size(); i++) {
		if (list1[i] > 0 && list1[i] > largest) {
			largest = list1[i];
		}
	}
	return largest;
}
<|endoftext|>