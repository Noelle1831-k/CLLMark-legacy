	string::iterator iter = p.begin();
	while(iter != p.end()){
		if(*iter >= 'A' && *iter <= 'Z'){
			iter++;
		}
		else if(*iter >= 'a' && *iter <= 'z'){
			iter++;
		}
		else if(*iter >= '0' && *iter <= '9'){
			iter++;
		}
		else if(*iter == '@'){
			iter++;
		}
		else {
			return false;
		}
	}
	return true;
}
<|endoftext|>