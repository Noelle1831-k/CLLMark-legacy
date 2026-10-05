	vector<int> res;
	int curmax = 0;
	for (int i = 0; i < list1.size(); i++) {
		if (list1[i] > curmax) {
			curmax = list1[i];
			res.clear();
			res.push_back(i);
		}
		else if (list1[i] == curmax) {
			res.push_back(i);
		}
	}
	return res;
}
int main() {
	vector<int> test = { 12, 33, 23, 10, 67, 89, 45, 667, 23, 12, 11, 10, 54 };
	cout << positionMax(test) << endl;
	test = { 1, 2, 2, 2, 4, 4, 4, 5, 5, 5, 5 };
	cout << positionMax(test) << endl;
	test = { 2, 1, 5, 6, 8, 3, 4, 9, 10, 11, 8, 12 };
	cout << positionMax(test) << endl;
	return 0;
}
<|endoftext|>