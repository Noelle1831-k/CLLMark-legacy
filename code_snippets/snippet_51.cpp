	map<int, int> myMap; 
	map<int, int> mySortMap; 
	for (int i = 0; i < myList.size(); i++) {
		myMap[myList[i]]++;
	}
	mySortMap[0] = myMap[0];
	for (int i = 1; i < myMap.size(); i++) {
		mySortMap[i] = mySortMap[i - 1] + myMap[i];
	}
	vector<int> mySortedList; 
	for (int i = 0; i < myList.size(); i++) {
		mySortedList.insert(mySortedList.begin() + mySortMap[myList[i]], myList[i]);
	}
	return mySortedList;
}
int main(int argc, char** argv) {
	vector<int> myList{12, 9, 28, 33, 69, 45};
	myList = countingSort(myList);
	for (int i = 0; i < myList.size(); i++) {
		cout << myList[i] << ", ";
	}
	return 0;
}
<|endoftext|>