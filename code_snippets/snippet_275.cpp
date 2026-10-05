	vector<int> res;
	int i1= nums1.size()-1;
	int i2= nums2.size()-1;
	while(n>0 && i1>=0 && i2>=0){
		int prod = nums1[i1]*nums2[i2];
		res.push_back(prod);
		n--;
		i1--;
		i2--;
	}
	while(n>0 && i1>=0){
		res.push_back(nums1[i1]);
		n--;
		i1--;
	}
	while(n>0 && i2>=0){
		res.push_back(nums2[i2]);
		n--;
		i2--;
	}
	while(n>0){
		res.push_back(0);
		n--;
	}
	return res;
}
<|endoftext|>