	map<int, int> my_map;
	int max = 0, temp;
	for (int i = 0; i < list1.size(); i++) {
		temp = my_map[list1[i]];
		my_map[list1[i]] = temp + 1;
		if (max < my_map[list1[i]])
			max = my_map[list1[i]];
	}
	for (auto it = my_map.begin(); it != my_map.end(); it++) {
		if (it->second == max)
			return it->first;
	}
}
int countOccurrence(vector<int> list1, int target) {
	map<int, int> my_map;
	int count = 0;
	for (int i = 0; i < list1.size(); i++) {
		my_map[list1[i]] = my_map[list1[i]] + 1;
	}
	count = my_map[target];
	return count;
}
int countOccurrenceBinary(vector<int> list1, int target) {
	map<int, int> my_map;
	int count = 0;
	for (int i = 0; i < list1.size(); i++) {
		my_map[list1[i]] = my_map[list1[i]] + 1;
	}
	count = my_map[target];
	return count;
}
int countOccurrenceBinary(vector<int> list1, int target) {
	map<int, int> my_map;
	int count = 0, i = 0, j = list1.size() - 1, temp, k;
	while (i <= j) {
		k = (i + j) / 2;
		if (list1[k] == target) {
			count = my_map[target];
			while (i > 0 && list1[i] == target)
				i--;
			count = count + (i + 1);
			while (j < list1.size() && list1[j] == target)
				j++;
			count = count + (list1.size() - j);
			return count;
		}
		temp = my_map[list1[k]];
		my_map[list1[k]] = temp + 1;
		if (list1[k] > target)
			j = k - 1;
		else
			i = k + 1;
	}
	return count;
}
int countOccurrenceBinary(vector<int> list1, int target) {
	map<int, int> my_map;
	int count = 0, i = 0, j = list1.size() - 1, temp, k;
	while (i <= j) {
		k = (i + j) / 2;
		if (list1[k] == target) {
			count = my_map[target];
			while (i > 0 && list1[i] == target)
				i--;
			count = count + (i + 1);
			while (j < list1.size() && list1[j] == target)
				j++;
			count = count + (list1.size() - j);
			return count;
		}
		temp = my_map[list1[k]];
		my_map[list1[k]] = temp + 1;
		if (list1[k] > target)
			j = k - 1;
		else
			i = k + 1;
	}
	return count;
}
/**
 * Write a function to count the number of occurrences of an element in a list using binary search.
 * > countOccurrenceBinary(vector<int>{2, 3, 8, 4, 7, 9, 8, 2, 6, 5, 1, 6, 1, 2, 3, 4, 6, 9, 1, 2}, 8)
 * 2
 * > countOccurrenceBinary(vector<int>{1, 3,