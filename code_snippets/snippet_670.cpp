	std::sort(li1.begin(), li1.end());
	std::sort(li2.begin(), li2.end());
	std::vector<int> res;
	std::vector<int>::iterator it1, it2;
	it1 = li1.begin();
	it2 = li2.begin();
	while(it1 != li1.end() && it2 != li2.end()){
		if(*it1 > *it2){
			res.push_back(*it1);
			it1++;
		}
		else if(*it1 < *it2){
			res.push_back(*it2);
			it2++;
		}
		else{
			it1++;
			it2++;
		}
	}
	while(it1 != li1.end()){
		res.push_back(*it1);
		it1++;
	}
	while(it2 != li2.end()){
		res.push_back(*it2);
		it2++;
	}
	return res;
}
int main(int argc, char** argv) {
	std::vector<int> l1, l2;
	l1.push_back(10);
	l1.push_back(15);
	l1.push_back(20);
	l1.push_back(25);
	l1.push_back(30);
	l1.push_back(35);
	l1.push_back(40);
	l2.push_back(25);
	l2.push_back(40);
	l2.push_back(35);
	std::vector<int> res = diff(l1, l2);
	for(int i : res){
		std::cout << i << ", ";
	}
	std::cout << std::endl;
	return 0;
}
<|endoftext|>