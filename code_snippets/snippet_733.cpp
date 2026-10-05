	map<int, int> frequencyMap;
	for (int i = 0; i < arrSize; i++) {
		map<int, int>::iterator itr = frequencyMap.find(arr[i]);
		if (itr != frequencyMap.end())
			frequencyMap[arr[i]] = frequencyMap[arr[i]] + 1;
		else
			frequencyMap[arr[i]] = 1;
	}
	for (const auto& itr : frequencyMap) {
		if (itr.second % 2 != 0)
			return itr.first;
	}
}
int main()
{
	vector<int> arr1 = {2, 3, 5, 4, 5, 2, 4, 3, 5, 2, 4, 4, 2};
	int n1 = arr1.size();
	cout << getOddOccurence(arr1, n1) << endl;
	vector<int> arr2 = {1, 2, 3, 2, 3, 1, 3};
	int n2 = arr2.size();
	cout << getOddOccurence(arr2, n2) << endl;
	vector<int> arr3 = {5, 7, 2, 7, 5, 2, 5};
	int n3 = arr3.size();
	cout << getOddOccurence(arr3, n3) << endl;
	return 0;
}
<|endoftext|>