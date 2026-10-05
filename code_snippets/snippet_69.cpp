	string ret = "";
	for (vector<int> x: testList) {
		bool valid = true;
		for (int y: x) {
			if (y % k != 0) {
				valid = false;
				break;
			}
		}
		if (valid) ret += "(" + to_string(x[0]) + ", " + to_string(x[1]) + ", " + to_string(x[2]) + "); ";
	}
	return ret;
}
int main() {
	vector<vector<int>> input0 = {{6, 24, 12}, {7, 9, 6}, {12, 18, 21}};
	int input1 = 6;
	string expectedOutput = "(6, 24, 12); ";
	string output = findTuples(input0, input1);
	assert(output == expectedOutput);
	cout << "PASSES TEST" << endl;
	return 0;
}
<|endoftext|>