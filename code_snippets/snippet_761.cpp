	string::iterator iter1, iter2;
	iter1 = str1.begin();
	iter2 = str2.begin();
	while(iter1 != str1.end()){
		while(iter2 != str2.end()){
			if(*iter1 == *iter2){
				iter2++;
				iter1++;
				break;
			}
			else {
				iter2 = str2.begin();
				iter1++;
			}
		}
		if(iter2 == str2.end()){
			return false;
		}
	}
	return true;
}
<|endoftext|>