	string even = "even";
	string odd = "odd";
	string evenNum = n, oddNum = n;
	string::iterator itr;
	itr = n.begin();
	while(itr != n.end()) {
		if(*itr == '0' || *itr == '2' || *itr == '4' || *itr == '6' || *itr == '8') {
			itr = n.erase(itr);
		}
		else {
			itr++;
		}
	}
	if(evenNum.size() == oddNum.size()) {
		return even;
	}
	else {
		return odd;
	}
}
<|endoftext|>