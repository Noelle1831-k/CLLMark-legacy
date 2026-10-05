	vector<int> negList;
	for (int i = 0; i < list1.size(); i++) {
		if (list1[i] < 0) {
			negList.push_back(list1[i]);
		}
	}
	return negList;
}
int main() {
	vector<int> myVec = {4, 8, 1, 2, -3, -7};
	vector<int> negList = negNos(myVec);
	for (int i = 0; i < negList.size(); i++) {
		cout << negList[i] << " ";
	}
	cout << endl;
	return 0;
}
<|endoftext|>