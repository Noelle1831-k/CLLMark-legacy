	for (int i = 0; i < testTup.size(); i++) {
		if (testTup[i] == -1) {
			return false;
		}
	}
	return true;
}
void printTup(tuple<int, int, int, int> testTup) {
	cout << get<0>(testTup) << ", " << get<1>(testTup) << ", " << get<2>(testTup) << ", " << get<3>(testTup) << endl;
}
void printTup(tuple<int, int, int, int> testTup1, tuple<int, int, int, int, int, int> testTup2) {
	printTup(testTup1);
	printTup(testTup2);
}
void printTup(tuple<int, int, int, int> testTup1, tuple<int, int, int, int, int, int> testTup2, tuple<int, int, int, int, int> testTup3) {
	printTup(testTup1);
	printTup(testTup2);
	printTup(testTup3);
}
void printVecTup(vector<tuple<int, int, int, int>> vtestTup) {
	for (int i = 0; i < vtestTup.size(); i++) {
		printTup(vtestTup[i]);
	}
}
void printVecTup(vector<tuple<int, int, int, int>> vtestTup1, vector<tuple<int, int, int, int, int, int>> vtestTup2) {
	printVecTup(vtestTup1);
	printVecTup(vtestTup2);
}
void printVecTup(vector<tuple<int, int, int, int>> vtestTup1, vector<tuple<int, int, int, int, int, int>> vtestTup2, vector<tuple<int, int, int, int, int>> vtestTup3) {
	printVecTup(vtestTup1);
	printVecTup(vtestTup2);
	printVecTup(vtestTup3);
}
void printVecVecTup(vector<vector<tuple<int, int, int, int>>> vvtestTup) {
	for (int i = 0; i < vvtestTup.size(); i++) {
		printVecTup(vvtestTup[i]);
	}
}
void printVecVecTup(vector<vector<tuple<int, int, int, int>>> vvtestTup1, vector<vector<tuple<int, int, int, int, int, int>>> vvtestTup2) {
	printVecVecTup(vvtestTup1);
	printVecVecTup(vvtestTup2);
}
void printVecVecTup(vector<vector<tuple<int, int, int, int>>> vvtestTup1, vector<vector<tuple<int, int, int, int, int, int>>> vvtestTup2, vector<vector<tuple<int, int, int, int, int>>> vvtestTup3) {
	printVecVecTup(vvtestTup1);
	printVecVecTup(vvtestTup2);
	printVecVecTup(vvtestTup3);
}
/**
 * Write a function to print the given tuples.
 * > printTup((4, 8, 1, 2))
 * 4, 8, 1, 2
 * > printTup((4, 8, 1, 2), (1, 8, 8, 8, 8