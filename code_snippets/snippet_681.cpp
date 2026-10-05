	int mul = 1;
	list<int> l = list1;
	while(l.size()>1){
		l.pop_front();
		l.pop_back();
		l.pop_front();
		l.pop_back();
	}
	while(l.size()>0){
		mul*=l.front();
		l.pop_front();
	}
	return mul;
}
int main (int argc, char const *argv[]) {
	std::vector<int> l = {1, 3, 5, 7, 4, 1, 6, 8};
	std::cout << mulEvenOdd(l) << '\n';
	std::vector<int> l1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	std::cout << mulEvenOdd(l1) << '\n';
	std::vector<int> l2 = {1, 5, 7, 9, 10};
	std::cout << mulEvenOdd(l2) << '\n';
	return 0;
}
<|endoftext|>