	vector<int> res;
	while(num1.size() != 0 && num2.size() != 0) {
		if(num1[0] > num2[0]) {
			res.push_back(num2[0]);
			num2.erase(num2.begin());
		} else {
			res.push_back(num1[0]);
			num1.erase(num1.begin());
		}
	}
	while(num1.size() != 0) {
		res.push_back(num1[0]);
		num1.erase(num1.begin());
	}
	while(num2.size() != 0) {
		res.push_back(num2[0]);
		num2.erase(num2.begin());
	}
	return res;
}
int main() {
	vector<int> num1;
	vector<int> num2;
	num1.push_back(1);
	num1.push_back(3);
	num1.push_back(5);
	num1.push_back(7);
	num1.push_back(9);
	num1.push_back(11);
	num2.push_back(0);
	num2.push_back(2);
	num2.push_back(4);
	num2.push_back(6);
	num2.push_back(8);
	num2.push_back(10);
	printList(combineLists(num1, num2));
	num1.clear();
	num2.clear();
	num1.push_back(1);
	num1.push_back(3);
	num1.push_back(5);
	num1.push_back(6);
	num1.push_back(8);
	num1.push_back(9);
	num2.push_back(2);
	num2.push_back(5);
	num2.push_back(7);
	num2.push_back(11);
	printList(combineLists(num1, num2));
	num1.clear();
	num2.clear();
	num1.push_back(1);
	num1.push_back(3);
	num1.push_back(7);
	num2.push_back(2);
	num2.push_back(4);
	num2.push_back(6);
	printList(combineLists(num1, num2));
	return 0;
}
<|endoftext|>