	unordered_map<int, int> mymap; 
	for (int i = 0; i < list1.size(); i++) {
		mymap[list1[i]]++; 
	}
	return mymap;
}
int main() {
	vector<int> mylist1 = {10, 10, 10, 10, 20, 20, 20, 20, 40, 40, 50, 50, 30};
	unordered_map<int, int> mymap = freqCount(mylist1); 
	for (auto it = mymap.begin(); it != mymap.end(); it++) {
		cout << (*it).first << " " << (*it).second << endl; 
	}
	return 0;
}
<|endoftext|>