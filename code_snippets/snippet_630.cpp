	map<int, int> mymap;
	int count = 0;
	for (int i = 0; i < nums1.size(); i++) {
		mymap[nums1[i]] = mymap[nums1[i]] + 1;
	}
	for (int i = 0; i < nums2.size(); i++) {
		mymap[nums2[i]] = mymap[nums2[i]] - 1;
		if (mymap[nums2[i]] > 0) count++;
	}
	return count;
}
<|endoftext|>