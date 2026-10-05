	int result = testList[0][1];
	for (int i = 1; i < testList.size(); i++) {
		if (testList[i][1] > result) {
			result = testList[i][1];
		}
	}
	return result;
}
int sum(vector<vector<int>> testList) {
	int result = 0;
	for (int i = 0; i < testList.size(); i++) {
		result += testList[i][0];
	}
	return result;
}
void printByFirst(vector<vector<int>> testList) {
	for (int i = 0; i < testList.size(); i++) {
		cout << testList[i][0] << " ";
	}
	cout << endl;
}
void printBySecond(vector<vector<int>> testList) {
	for (int i = 0; i < testList.size(); i++) {
		cout << testList[i][1] << " ";
	}
	cout << endl;
}
void printByFirstDescending(vector<vector<int>> testList) {
	int result = testList[0][0];
	for (int i = 1; i < testList.size(); i++) {
		if (testList[i][0] > result) {
			result = testList[i][0];
		}
	}
	for (int i = 0; i < testList.size(); i++) {
		if (testList[i][0] == result) {
			cout << testList[i][0] << " ";
		}
	}
	cout << endl;
}
void printBySecondDescending(vector<vector<int>> testList) {
	int result = testList[0][1];
	for (int i = 1; i < testList.size(); i++) {
		if (testList[i][1] > result) {
			result = testList[i][1];
		}
	}
	for (int i = 0; i < testList.size(); i++) {
		if (testList[i][1] == result) {
			cout << testList[i][1] << " ";
		}
	}
	cout << endl;
}
void printByAscending(vector<vector<int>> testList) {
	for (int i = 0; i < testList.size(); i++) {
		cout << testList[i][0] << " " << testList[i][1] << " ";
	}
	cout << endl;
}
/**
 * Write a function to print the given tuple records by their first values and their second values in descending order.
 * > print