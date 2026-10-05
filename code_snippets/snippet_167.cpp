	string prefix = arr[0];
	for (int i = 1; i < n; i++) {
		while (arr[i].find(prefix) != 0) {
			prefix.pop_back();
		}
	}
	return prefix;
}
int main() {
	string prefix = commonPrefix({ "tablets", "tables", "taxi", "tamarind" }, 4);
	cout << prefix << endl;
	return 0;
}
<|endoftext|>