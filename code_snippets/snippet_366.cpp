	list<int> l1,l2;
	l1=list1;
	l2=list2;
	list<int>::iterator p1=l1.begin();
	list<int>::iterator p2=l2.begin();
	while(p1!=l1.end()){
		while(p2!=l2.end()){
			if(*p1==*p2){
				return true;
			}
			p2++;
		}
		p1++;
		p2=l2.begin();
	}
	return false;
}
<|endoftext|>