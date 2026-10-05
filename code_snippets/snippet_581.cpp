	numList.insert(numList.end(), numList.begin() + 1);
	numList.erase(numList.begin());
	return numList;
}
vector<int> moveFirst(vector<int> numList) {
	numList.insert(numList.begin(), numList.back());
	numList.pop_back();
	return numList;
}
vector<int> moveFirst(vector<int> numList, int k) {
	numList.insert(numList.end(), numList.begin() + k);
	numList.erase(numList.begin(), numList.begin() + k);
	return numList;
}
vector<int> moveLast(vector<int> numList, int k) {
	numList.insert(numList.begin(), numList.end() - k);
	numList.erase(numList.end() - k, numList.end());
	return numList;
}
vector<int> moveFirst(vector<int>& numList, int k) {
	while (k--) {
		numList.insert(numList.begin() + 1, numList.front());
		numList.erase(numList.begin());
	}
	return numList;
}
vector<int> moveLast(vector<int>& numList, int k) {
	while (k--) {
		numList.push_back(numList.back());
		numList.erase(numList.end() - 1);
	}
	return numList;
}
vector<int> moveFirst(vector<int>& numList, int k) {
	while (k--) {
		numList.insert(numList.begin() + 1, numList.front());
		numList.erase(numList.begin());
	}
	return numList;
}
vector<int> moveLast(vector<int>& numList, int k) {
	while (k--) {
		numList.push_back(numList.back());
		numList.erase(numList.end() - 1);
	}
	return numList;
}
vector<int> moveFirst(vector<int>& numList, int k) {
	while (k--) {
		numList.insert(numList.begin() + 1, numList.front());
		numList.erase(numList.begin());
	}
	return numList;
}
