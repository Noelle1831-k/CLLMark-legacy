	for (int i = 0; i < arrSize; i++) {
		for (int j = i + 1; j < arrSize; j++) {
			for (int k = j + 1; k < arrSize; k++) {
				if (a[i] + a[j] + a[k] == sum) {
					return {a[i], a[j], a[k]};
				}
			}
		}
	}
	return {};
}
int main() {
	vector<int> a{1, 4, 45, 6, 10, 8};
	int sum = 22;
	vector<int> res = findTripletArray(a, a.size(), sum);
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << " ";
	}
	cout << endl;
	return 0;
}
<|endoftext|>