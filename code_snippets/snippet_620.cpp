	map<int, int> uniques; 
	for (const auto& x : testList) {
		uniques[x[1]]++;
	}
	string out = "{";
	for (const auto& x : uniques) {
		out += to_string(x.first) + ": " + to_string(x.second) + ", ";
	}
	out += "}";
	return out;
}
int main() {
	vector<vector<int>> testList{ {3, 4}, {1, 2}, {2, 4}, {8, 2}, {7, 2}, {8, 1}, {9, 1}, {8, 4}, {10, 4} };
	cout << getUnique(testList) << endl;
	testList = { {4, 5}, {2, 3}, {3, 5}, {9, 3}, {8, 3}, {9, 2}, {10, 2}, {9, 5}, {11, 5} };
	cout << getUnique(testList) << endl;
	testList = { {6, 5}, {3, 4}, {2, 6}, {11, 1}, {8, 22}, {8, 11}, {4, 3}, {14, 3}, {11, 6} };
	cout << getUnique(testList) << endl;
}
<|endoftext|>