	for(int i = 0; i < testList.size(); i++){
		if(testList[i].size() != k){
			return false;
		}
	}
	return true;
}
int main() {
	vector<vector<int>> testList{ {4, 4}, {4, 4, 4}, {4, 4}, {4, 4, 4, 4}, {4} };
	cout << checkKElements(testList, 4) << endl; 
	testList = { {7, 7, 7}, {7, 7} };
	cout << checkKElements(testList, 7) << endl; 
	testList = { {9, 9}, {9, 9, 9, 9} };
	cout << checkKElements(testList, 7) << endl; 
	return 0;
}
<|endoftext|>