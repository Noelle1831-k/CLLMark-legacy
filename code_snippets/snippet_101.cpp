	priority_queue<int> heap;
	for(int i=0;i<num1.size();i++){
		heap.push(num1[i]);
	}
	for(int i=0;i<num2.size();i++){
		heap.push(num2[i]);
	}
	for(int i=0;i<num3.size();i++){
		heap.push(num3[i]);
	}
	vector<int> res;
	while(!heap.empty()){
		res.push_back(heap.top());
		heap.pop();
	}
	return res;
}
int main(void) {
	vector<int> num1, num2, num3;
	num1 = {25, 24, 15, 4, 5, 29, 110};
	num2 = {19, 20, 11, 56, 25, 233, 154};
	num3 = {24, 26, 54, 48};
	vector<int> res = mergeSortedList(num1, num2, num3);
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << " ";
	}
	cout << endl;
	return 0;
}
<|endoftext|>