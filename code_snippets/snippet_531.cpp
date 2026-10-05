	list1.erase(list1.begin() + l - 1);
	return list1;
}
int main() {
	vector<int> test = { 1, 1, 2, 3, 4, 4, 5, 1 };
	test = removeKthElement(test, 3);
	for (int i : test)
		cout << i << " ";
	cout << endl;
	test = { 0, 0, 1, 2, 3, 4, 4, 5, 6, 6, 6, 7, 8, 9, 4, 4 };
	test = removeKthElement(test, 4);
	for (int i : test)
		cout << i << " ";
	cout << endl;
	test = { 10, 10, 15, 19, 18, 18, 17, 26, 26, 17, 18, 10 };
	test = removeKthElement(test, 5);
	for (int i : test)
		cout << i << " ";
	cout << endl;
	return 0;
}
<|endoftext|>