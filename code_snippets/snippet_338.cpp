	testList.insert(testList.begin(), testList.back());
	testList.erase(testList.begin() + testList.size() - 1);
	return testList;
}
int main() {
	moveFirst(vector<int>{1, 2, 3, 4});
	moveFirst(vector<int>{0, 1, 2, 3});
	moveFirst(vector<int>{9, 8, 7, 1});
}
<|endoftext|>