	priority_queue<pair<int, pair<int, int>>> pq; 
	for (int i = 0; i < p; i++) {
		pq.push({a[i], {b[i], c[i]}});
	}
	vector<int> res;
	while (r--) {
		pair<int, pair<int, int>> ele = pq.top();
		pq.pop();
		res.push_back(ele.first);
		if (pq.empty()) {
			break;
		}
		ele = pq.top();
		pq.pop();
		pq.push({ele.first, {ele.second.first, ele.second.second + 1}}); 
	}
	return res;
}
int main(int argc, char** argv) {
	vector<int> a = {1, 4, 10};
	vector<int> b = {2, 15, 20};
	vector<int> c = {10, 12};
	printf("findCloset(vector<int>{1, 4, 10}, vector<int>{2, 15, 20}, vector<int>{10, 12}, 3, 3, 2) = %s\n", 
		(findCloset(a, b, c, 3, 3, 2) == vector<int>{10, 15, 10}) ? "true" : "false");
	vector<int> aa = {20, 24, 100};
	vector<int> bb = {2, 19, 22, 79, 800};
	vector<int> cc = {10, 12, 23, 24, 119};
	printf("findCloset(vector<int>{20, 24, 100}, vector<int>{2, 19, 22, 79, 800}, vector<int>{10, 12, 23, 24, 119}, 3, 5, 5) = %s\n", 
		(findCloset(aa, bb, cc, 3, 5, 5) == vector<int>{24, 22, 23}) ? "true" : "false");
	vector<int> aaa = {2, 5, 11};
	vector<int> bbb = {3, 16, 21};
	vector<int> ccc = {11, 13};
	printf("findCloset(vector<int>{2, 5, 11}, vector<int>{3, 16, 21}, vector<int>{11, 13}, 3, 3, 2) = %s\n", 
		(findCloset(aaa, bbb, ccc, 3, 3, 2) == vector<int>{11, 16, 11}) ? "true" : "false");
	return 0;
}<|endoftext|>