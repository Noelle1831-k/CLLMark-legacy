	unordered_map<string, int> res{};
	for (auto it1=d1.begin(); it1!=d1.end(); it1++) {
		string k1=it1->first;
		int v1=it1->second;
		for (auto it2=d2.begin(); it2!=d2.end(); it2++) {
			string k2=it2->first;
			int v2=it2->second;
			if (k1==k2) {
				res[k1]=v1+v2;
			} else {
				res[k1]=v1;
				res[k2]=v2;
			}
		}
	}
	return res;
}
int main() {
	unordered_map<string, int> d1, d2;
	string k1, k2;
	int v1, v2;
	while (cin >> k1 >> v1 >> k2 >> v2) {
		d1[k1] = v1;
		d2[k2] = v2;
	}
	unordered_map<string, int> res = mergeDict(d1, d2);
	for (auto it: res) {
		cout << it.first << " " << it.second << endl;
	}
}
<|endoftext|>