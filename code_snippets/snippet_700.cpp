	int largest = INT_MIN;
	int largest_idx = 0;
	for(int i = 0; i < lists.size(); i++) {
		int current_sum = 0;
		for(int j = 0; j < lists[i].size(); j++) {
			current_sum += lists[i][j];
		}
		if(current_sum > largest) {
			largest = current_sum;
			largest_idx = i;
		}
	}
	return lists[largest_idx];
}
int main() {
	vector<vector<int>> list_1;
	list_1.push_back(vector<int>({1, 2, 3}));
	list_1.push_back(vector<int>({4, 5, 6}));
	list_1.push_back(vector<int>({10, 11, 12}));
	list_1.push_back(vector<int>({7, 8, 9}));
	printList(maxSumList(list_1));
	list_1.clear();
	list_1.push_back(vector<int>({3, 2, 1}));
	list_1.push_back(vector<int>({6, 5, 4}));
	list_1.push_back(vector<int>({12, 11, 10}));
	printList(maxSumList(list_1));
	list_1.clear();
	list_1.push_back(vector<int>({2, 3, 1}));
	printList(maxSumList(list_1));
	return 0;
}
<|endoftext|>