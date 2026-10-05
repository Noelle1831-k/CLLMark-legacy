	vector<int> res;
	int i = 0;
	int j = 0;
	while(i < lst1.size() && j < lst2.size()) {
		if(lst1[i] > lst2[j]) {
			res.push_back(lst2[j]);
			j++;
		}
		else {
			res.push_back(lst1[i]);
			i++;
		}
	}
	while(i < lst1.size()) {
		res.push_back(lst1[i]);
		i++;
	}
	while(j < lst2.size()) {
		res.push_back(lst2[j]);
		j++;
	}
	return res;
}
int main() {
	vector<int> res = sumList(vector<int>{10, 20, 30}, vector<int>{15, 25, 35});
	for(int i = 0; i < res.size(); i++) {
		cout << res[i] << " ";
	}
	cout << endl;
	return 0;
}
<|endoftext|>