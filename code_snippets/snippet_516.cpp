	vector<int> squares;
	for (int i = a; i <= b; i++) {
		int current = 1;
		while (current * current < i) {
			current++;
		}
		if (current * current == i) {
			squares.push_back(i);
		}
	}
	return squares;
}
int main() {
	vector<int> squares1 = perfectSquares(1, 30);
	for (int i = 0; i < squares1.size(); i++) {
		cout << squares1[i] << ", ";
	}
	cout << endl;
	vector<int> squares2 = perfectSquares(50, 100);
	for (int i = 0; i < squares2.size(); i++) {
		cout << squares2[i] << ", ";
	}
	cout << endl;
	vector<int> squares3 = perfectSquares(100, 200);
	for (int i = 0; i < squares3.size(); i++) {
		cout << squares3[i] << ", ";
	}
	cout << endl;
	return 0;
}
<|endoftext|>