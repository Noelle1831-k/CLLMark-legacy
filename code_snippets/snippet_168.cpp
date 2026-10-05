	map<int, int> mymap;
	for (int i = 0; i < n; i++) {
		mymap[arr[i]]++;
	}
	int count = 0;
	for (auto it = mymap.begin(); it != mymap.end(); it++) {
		count += (mymap.find(it->first + k) != mymap.end()) ? (it->second * mymap.find(it->first + k)->second) : 0;
	}
	return count;
}
int main() {
	countPairs({ 1, 5, 3, 4, 2 }, 5, 3);
	countPairs({ 8, 12, 16, 4, 0, 20 }, 6, 4);
	countPairs({ 2, 4, 1, 3, 4 }, 5, 2);
	return 0;
}
<|endoftext|>