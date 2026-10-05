	int size = myList.size();
	for (int gap = size / 2; gap > 0; gap /= 2) {
		for (int i = gap; i < size; i++) {
			int temp = myList[i];
			int j = i;
			while (j >= gap && myList[j - gap] > temp) {
				myList[j] = myList[j - gap];
				j -= gap;
			}
			myList[j] = temp;
		}
	}
	return myList;
}
int main() {
	vector<int> myList{12, 23, 4, 5, 3, 2, 12, 81, 56, 95};
	myList = shellSort(myList);
	for (int i = 0; i < myList.size(); i++) {
		cout << myList[i] << " ";
	}
	cout << endl;
}
<|endoftext|>