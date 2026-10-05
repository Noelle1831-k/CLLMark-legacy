	m = m % n;
	reverse(list1.begin(), list1.begin() + m);
	reverse(list1.begin() + m, list1.end());
	reverse(list1.begin(), list1.end());
	return list1;
}
int main() {
	vector<int> myVec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int m = 3;
	int n = 10;
	printVec(rotateRight(myVec, m, n));
	return 0;
}
<|endoftext|>