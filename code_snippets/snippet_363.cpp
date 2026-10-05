	int result = 0;
	for (int i = 0; i < list1.size(); i++) {
		for (int j = i + 1; j < list1.size(); j++) {
			if (list1[i][0] * list1[j][1] < list1[i][1] * list1[j][0]) {
				result = list1[i][0] * list1[j][1];
			}
			else {
				result = list1[i][1] * list1[j][0];
			}
		}
	}
	return result;
}
void count_even_odd(vector<int> list1) {
	int count_even = 0;
	int count_odd = 0;
	for (int i = 0; i < list1.size(); i++) {
		if (list1[i] % 2 == 0) {
			count_even++;
		}
		else {
			count_odd++;
		}
	}
	cout << "Even count is " << count_even << " and Odd count is " << count_odd << endl;
}
void count_even_odd_list_comprehension(vector<int> list1) {
	int count_even = 0;
	int count_odd = 0;
	for (int i = 0; i < list1.size(); i++) {
		if (list1[i] % 2 == 0) {
			count_even++;
		}
		else {
			count_odd++;
		}
	}
	cout << "Even count is " << count_even << " and Odd count is " << count_odd << endl;
}
void count_even_odd_list_comprehension_less_than_5(vector<int> list1) {
	int count_even = 0;
	int count_odd = 0;
	for (int i = 0; i < list1.size(); i++) {
		if (list1[i] % 2 == 0) {
			count_even++;
		}
		else {
			count_odd++;
		}
	}
	cout << "Even count is " << count_even << " and Odd count is " << count_odd << endl;
}
void count_even_odd_list_comprehension_greater_than_5(vector<int> list1) {
	int count_even = 0;
	int count_odd = 0;
	for (int i = 0; i < list1.size(); i++) {
		if (list1[i] % 2 == 0) {
			count_even++;
		}
		else {
			count_odd++;
		}
	}
	cout << "Even count is " << count_even << " and Odd count is " << count_odd << endl;
}
void count_even_odd_list_comprehension_greater_than_8(vector<int> list1) {
	int count_even = 0;
	int count_odd = 0;
	for (int i = 0; i < list1.size(); i++) {
		if (list1[i] % 2 == 0) {
			count