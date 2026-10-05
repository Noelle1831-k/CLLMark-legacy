	int count = 0;
	for (int i = 0; i < tup.size(); i++) {
		if (tup[i] == x) count++;
	}
	return count;
}
int countX2(vector<int> vec, int x) {
	int count = 0;
	for (int i = 0; i < vec.size(); i++) {
		if (vec[i] == x) count++;
	}
	return count;
}
int countX3(list<int> l, int x) {
	int count = 0;
	for (list<int>::iterator iter = l.begin(); iter != l.end(); iter++) {
		if (*iter == x) count++;
	}
	return count;
}
int countX4(deque<int> d, int x) {
	int count = 0;
	for (deque<int>::iterator iter = d.begin(); iter != d.end(); iter++) {
		if (*iter == x) count++;
	}
	return count;
}
int countX5(set<int> s, int x) {
	int count = 0;
	for (set<int>::iterator iter = s.begin(); iter != s.end(); iter++) {
		if (*iter == x) count++;
	}
	return count;
}
int countX6(multiset<int> ms, int x) {
	int count = 0;
	for (multiset<int>::iterator iter = ms.begin(); iter != ms.end(); iter++) {
		if (*iter == x) count++;
	}
	return count;
}
int countX7(map<int, int> m, int x) {
	int count = 0;
	for (map<int, int>::iterator iter = m.begin(); iter != m.end(); iter++) {
		if (iter->first == x) count++;
	}
	return count;
}
/**
 * Write a c++ function to count the occurences of an element in a unordered_map
 * > countX8(vector<int>{10, 8, 5, 2, 10, 15, 10, 8, 5, 8, 8, 2}, 4)
 * 0
 * > countX8(vector<int>{10, 8, 5, 2, 10, 15, 10, 8, 5, 8, 8, 2}, 10)
 * 3
 * > countX8(vector<int>{10, 8, 5, 2, 10, 15, 10