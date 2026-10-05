	map<int, vector<int>> groups;
	for (const auto &v : testList) {
		int firstElement = v[0];
		groups[firstElement].push_back(v[1]);
	}
	vector<vector<int>> ret = {};
	for (const auto &v : groups) {
		if (v.second.size() == 1) ret.push_back({v.first});
		else {
			sort(v.second.begin(), v.second.end());
			ret.push_back({v.first});
			for (const auto &v2 : v.second) ret.push_back({v.first, v2});
		}
	}
	return ret;
}
string joinStrings(vector<string> strings) {
	string ret = "";
	for (const auto &v : strings) ret += " " + v;
	return ret.substr(1);
}
int countStrings(vector<string> strings) {
	map<string, int> groups;
	for (const auto &v : strings) groups[v]++;
	int ret = 0;
	for (const auto &v : groups) ret += v.second;
	return ret;
}
string getMostCommonString(vector<string> strings) {
	map<string, int> groups;
	for (const auto &v : strings) groups[v]++;
	string ret = "";
	for (const auto &v : groups) ret += (v.second > groups[ret] ? v.first : "");
	return ret;
}
string getLeastCommonString(vector<string> strings) {
	map<string, int> groups;
	for (const auto &v : strings) groups[v]++;
	string ret = "";
	for (const auto &v : groups) ret += (v.second < groups[ret] ? v.first : "");
	return ret;
}
string getMostCommonAndLeastCommonString(vector<string> strings) {
	map<string, int> groups;
	for (const auto &v : strings) groups[v]++;
	string ret = "";
	for (const auto &v : groups) ret += (v.second > groups[ret] ? v.first : "");
	string ret2 = "";
	for (const auto &v : groups) ret2 += (v.second < groups[ret2] ? v.first : "");
	return ret + " " + ret2;
}
string getMostCommonAndLeastCommonStringWithCounts(vector<string> strings) {
	map<string, int> groups;
	for (const auto &v : strings) groups[v]++;
	string ret = "";
	for (const auto &v : groups) ret += (v.second > groups[ret] ? v.first + " " + to_string(v.second) + " " : "");
	string ret2 = "";
	for (const auto &v : groups) ret2 += (v.second < groups[ret2] ? v.first + " " + to_string(v.second) + " " : "");
	return ret.substr(0, ret.size() - 1) + " " + ret2.substr(0, ret2.size() - 1);
}
string getMostCommonAndLeastCommonStringWithCounts(vector<string> strings) {
	map<string, int> groups;
	for (const auto &v : strings) groups[v]++;
	string ret = "";
	for (const auto &v : groups) ret += (v.second > groups[ret] ? v.first + " " + to_string(v.second) + " " : "");
	string ret2 = "";
	for (const auto &v : groups) ret2 += (v.second < groups[ret2] ? v.first + " " + to_string(v.second) + " " : "");
	return ret.substr(0, ret.size() - 1) + " " + ret2.substr(0, ret2.size() - 1);
}
string getMostCommonAndLeastCommonStringWithCounts(vector<string> strings) {
	map<string, int> groups;
	for (const auto &v : strings) groups[v]++;
	string ret = "";
	for (const auto &v : groups) ret += (v.second > groups[ret] ? v.first + " " + to_string(v.second) + " " : "");
	string ret2 = "";
	for (const auto &v : groups) ret2 += (v.second < groups[ret2]