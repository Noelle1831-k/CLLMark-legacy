	int i = 0, odd = 0, even = 0, num = 0;
	while (i < list1.size()) {
		num = list1[i];
		if (num % 2 == 0) {
			even = num;
		} else {
			odd = num;
		}
		i++;
	}
	return even / odd;
}
int main() {
	vector<int> myVec{1, 3, 5, 7, 4, 1, 6, 8};
	cout << divEvenOdd(myVec) << endl;
}
<|endoftext|>