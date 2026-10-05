	string s = to_string(num);
	string pal;
	while(s.back() != '0'){
		s.back()--;
		s.insert(0,s.back());
		string tmp(s);
		s.back()--;
		s.erase(0,1);
		if(tmp == s)
		{
			pal = tmp;
			break;
		}
	}
	return stoi(pal);
}
<|endoftext|>