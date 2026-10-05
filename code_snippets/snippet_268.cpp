	vector<int> res;
	for(auto it1=list1.begin();it1!=list1.end();it1++){
		for(auto it2=it1->begin();it2!=it1->end();it2++){
			res.push_back(*it2);
		}
	}
	return res;
}
<|endoftext|>