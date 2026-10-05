	int firstElement = newlist.front();
	int lastElement = newlist.back();
	newlist.erase(newlist.begin());
	newlist.push_back(firstElement);
	return newlist;
}
int main() {
	vector<int> myVec = {4, 5, 6};
	myVec = swapList(myVec);
	for (auto x : myVec)
		cout << x << " ";
	cout << "\n";
	return 0;
}
<|endoftext|>