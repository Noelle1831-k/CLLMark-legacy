	vector<double> res;
	int size = nums.size();
	int colNum = nums[0].size();
	for(int i = 0; i < colNum; i++){
		int tmp = 0;
		for(int j = 0; j < size; j++){
			tmp += nums[j][i];
		}
		res.push_back(round(tmp / size));
	}
	return res;
}
<|endoftext|>