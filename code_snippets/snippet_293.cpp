	vector<int> res;
	m = m % n;
	while(n>0){
		res.push_back(list1[n-m-1]);
		n--;
	}
	while(m>0){
		res.push_back(list1[n-1]);
		m--;
	}
	while(n>0){
		res.push_back(list1[n-1]);
		n--;
	}
	return res;
}
int main () {
	vector<int> list1;
	list1.push_back(1);
	list1.push_back(2);
	list1.push_back(3);
	list1.push_back(4);
	list1.push_back(5);
	list1.push_back(6);
	list1.push_back(7);
	list1.push_back(8);
	list1.push_back(9);
	list1.push_back(10);
	list1 = rotateLeft(list1, 3, 4);
	for (int i = 0; i < list1.size(); ++i)
		cout << list1[i] << " ";
	cout << endl;
	list1 = rotateLeft(list1, 2, 2);
	for (int i = 0; i < list1.size(); ++i)
		cout << list1[i] << " ";
	cout << endl;
	list1 = rotateLeft(list1, 5, 2);
	for (int i = 0; i < list1.size(); ++i)
		cout << list1[i] << " ";
	cout << endl;
	return 0;
}
<|endoftext|>