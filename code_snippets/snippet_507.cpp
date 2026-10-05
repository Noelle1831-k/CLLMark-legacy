	vector<int> res;
	for (int i = 0; i < list1.size(); i++) {
		res.push_back(list1[i]);
		res.push_back(list2[i]);
		res.push_back(list3[i]);
	}
	return res;
}
int main() {
	vector<int> list1, list2, list3;
	list1 = {1, 2, 3, 4, 5, 6, 7};
	list2 = {10, 20, 30, 40, 50, 60, 70};
	list3 = {100, 200, 300, 400, 500, 600, 700};
	vector<int> res = interleaveLists(list1, list2, list3);
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << " ";
	}
	cout << endl;
	list1 = {10, 20};
	list2 = {15, 2};
	list3 = {5, 10};
	res = interleaveLists(list1, list2, list3);
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << " ";
	}
	cout << endl;
	list1 = {11, 44};
	list2 = {10, 15};
	list3 = {20, 5};
	res = interleaveLists(list1, list2, list3);
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << " ";
	}
	cout << endl;
	return 0;
}
<|endoftext|>