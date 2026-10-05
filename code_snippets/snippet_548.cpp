	vector<vector<int>> ans;
	for (int i = testTup[0] - 1; i <= testTup[0] + 1; i++) {
		for (int j = testTup[1] - 1; j <= testTup[1] + 1; j++) {
			if (i >= 1 && i <= 8 && j >= 1 && j <= 8) {
				ans.push_back(vector<int>{i, j});
			}
		}
	}
	return ans;
}
vector<vector<vector<int>>> winPatterns() {
	vector<vector<vector<int>>> ans;
	ans.push_back({vector<int>{0, 0}, vector<int>{0, 1}, vector<int>{0, 2}});
	ans.push_back({vector<int>{0, 0}, vector<int>{0, 1}, vector<int>{1, 2}});
	ans.push_back({vector<int>{0, 0}, vector<int>{1, 1}, vector<int>{2, 2}});
	ans.push_back({vector<int>{0, 1}, vector<int>{0, 2}, vector<int>{1, 2}});
	ans.push_back({vector<int>{0, 0}, vector<int>{1, 0}, vector<int>{2, 0}});
	ans.push_back({vector<int>{0, 0}, vector<int>{1, 1}, vector<int>{2, 2}});
	ans.push_back({vector<int>{2, 0}, vector<int>{2, 1}, vector<int>{2, 2}});
	ans.push_back({vector<int>{0, 2}, vector<int>{1, 2}, vector<int>{2, 2}});
	return ans;
}
bool isWinner(vector<vector<char>> b, vector<vector<int>> c) {
	char player = b[c[0][0]][c[0][1]];
	vector<vector<vector<int>>> wins = winPatterns();
	for (vector<vector<int>> w : wins) {
		char checker = b[w[0][0]][w[0][1]];
		if (checker != player) continue;
		int count = 1;
		for (int i = 1; i < w.size(); i++) {
			if (b[w[i][0]][w[i][1]] != checker) break;
			count++;
		}
		if (count == 3) return true;
	}
	return false;
}
bool isGameOver(vector<vector<char>> b) {
	char player = b[0][0];
	vector<vector<vector<int>>> wins = winPatterns();
	for (vector<vector<int>> w : wins) {
		char checker = b[w[0][0]][w[0][1]];
		if (checker != player) continue;
		int count = 1;
		for (int i = 1; i < w.size(); i++) {
			if (b[w[i][0]][w[i][1]] != checker) break;
			count++;
		}
		if (count == 3) return true;
	}
	return false;
}
bool nextStep(vector<vector<char>> b, vector<vector<int>> c) {
	char player = b[c[0][0]][c[0][1]];
	vector<vector<vector<int>>> wins = winPatterns();
	for (vector<vector<int>> w : wins) {
		char checker = b[w[0][0]][w[0][1]];
		if (checker != player) continue;
		int count = 1;
		for (int i = 1; i < w.size(); i++) {
			if (b[w[i][0]][w[i][1]] != checker) break;
			count++;
		}
		if (count == 2) {
			int newC = w[w.size() - 1][0];
			int newR = w[w.size() - 1][1];
			b[newC][newR] = player;
			return true;
		}
	}
	return false;
}
bool nextStepWithRandom(vector<vector<char>> b, vector<vector<int>> c) {
	char player = b[c[0][0]][c[0][1]];
	vector<vector<vector<int>>> wins = winPatterns();
	for (vector<vector<int>> w : wins) {
		char checker = b[w[0][0]][w[0][1]];
		if (checker != player) continue;
		int count = 1;
		for (int i = 1; i < w.size(); i++) {
			if (b[w[i][0]][w[i][1]] != checker) break;
			count++;
		}
		if (count == 2) {
			int newC = w[w.size() - 1][0];
			int newR = w[w.size() - 1][1];
			b[newC][newR] = player;
			return true;
		}
	}
	int newC = rand() % 8;
	int newR = rand() % 8;
	while (b[newC][newR] != '.') {
		newC = rand() % 8;
		newR = rand() % 8;
	}
	b[newC][newR] = player;
	return true;
}
bool nextStepWithRandomDiff(vector<vector<char>> b, vector<vector<int>> c) {
	char player = b[c[0][0]][c[0][1]];
	vector<vector<vector<int>>> wins = winPatterns();
	for (vector<vector<int>> w : wins) {
		char checker = b[w[0][0]][w[0][1]];
		if (checker != player) continue;
		int count = 1;
		for (int i = 1; i < w.size(); i++) {
			if (b[w[i][0]][w[i][1]] != checker) break;
			count++;
		}
		if (count == 2) {
			int newC = w[w.size() - 1][0];
			int newR = w[w.size() - 1][1];
			b[newC][newR] = player;
