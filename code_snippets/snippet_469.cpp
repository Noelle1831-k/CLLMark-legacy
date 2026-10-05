	vector<int> res;
	for(int i = 0; i < n; i++){
		res.push_back(list[i]);
	}
	return res;
}
int main() {
	cout << nthItems({1, 2, 3, 4, 5, 6, 7, 8, 9}, 2) << endl;
	cout << nthItems({10, 15, 19, 17, 16, 18}, 3) << endl;
	cout << nthItems({14, 16, 19, 15, 17}, 4) << endl;
}
<|endoftext|>