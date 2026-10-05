	map<int, int> myMap;
	vector<int> myVec;
	for (const auto& i : testList)
		for (const auto& j : i)
			myMap[j]++;
	for (auto& i : myMap)
		if (i.second == 1)
			myVec.push_back(i.first);
	return myVec;
}
vector<pair<int, int>> pairUnique(vector<pair<int, int>> inputList) {
	map<int, int> myMap;
	vector<pair<int, int>> outputList;
	for (const auto& i : inputList)
		myMap[i.first]++;
	for (const auto& i : inputList)
		if (myMap[i.first] == 1)
			outputList.push_back(i);
	return outputList;
}
vector<pair<int, int>> pairUnique(vector<pair<int, int>> inputList) {
	map<int, int> myMap;
	vector<pair<int, int>> outputList;
	for (const auto& i : inputList)
		myMap[i.first]++;
	for (const auto& i : inputList)
		if (myMap[i.first] == 1)
			outputList.push_back(i);
	return outputList;
}
vector<pair<int, int>> pairUnique(vector<pair<int, int>> inputList) {
	map<int, int> myMap;
	vector<pair<int, int>> outputList;
	for (const auto& i : inputList)
		myMap[i.first]++;
	for (const auto& i : inputList)
		if (myMap[i.first] == 1)
			outputList.push_back(i);
	return outputList;
}
