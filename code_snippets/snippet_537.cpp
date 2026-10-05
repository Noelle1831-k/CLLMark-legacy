(int i=0,j=0);vector<string> strNum,resStr;for(int i=0;i<testStr.size();i++){if(testStr[i]>='0' && testStr[i]<='9'){int start = i;for(;i<testStr.size() && testStr[i]>='0' && testStr[i]<='9';i++){}strNum.push_back(testStr.substr(start,i-start));}
int longestIncreasingSubsequence(string text) {
	map<char, vector<int> > mp;
	map<char, int> dp;
	for (int i = 0; i < text.size(); i++) {
		mp[text[i]].push_back(i);
	}
	for (const auto &i : mp) {
		dp[i.first] = 1;
		for (const auto &j : mp) {
			if (i.first == j.first) continue;
			if (i.second[0] > j.second[0] && (i.second[0] > j.second[j.second.size() - 1])) dp[i.first] = max(dp[i.first], dp[j.first] + 1);
		}
	}
	int m = 0;
	for (const auto &i : dp)
		m = max(m, i.second);
	return m;
}
int longestIncreasingSubsequence2(string text) {
	map<char, vector<int> > mp;
	map<char, int> dp;
	for (int i = 0; i < text.size(); i++) {
		mp[text[i]].push_back(i);
	}
	for (const auto &i : mp) {
		dp[i.first] = 1;
		for (const auto &j : mp) {
			if (i.first == j.first) continue;
			if (i.second[0] > j.second[0] && (i.second[0] > j.second[j.second.size() - 1])) dp[i.first] = max(dp[i.first], dp[j.first] + 1);
		}
	}
	int m = 0;
	for (const auto &i : dp)
		m = max(m, i.second);
	return m;
}
int longestIncreasingSubsequence2(string text) {
	map<char, vector<int> > mp;
	map<char, int> dp;
	for (int i = 0; i < text.size(); i++) {
		mp[text[i]].push_back(i);
	}
	for (const auto &i : mp) {
		dp[i.first] = 1;
		for (const auto &j : mp) {
			if (i.first == j.first) continue;
			if (i.second[0] > j.second[0] && (i.second[0] > j.second[j.second.size() - 1])) dp[i.first] = max(dp[i.first], dp[j.first] + 1);
		}
	}
	int m = 0;
	for (const auto &i : dp)
		m = max(m, i.second);
	return m;
}
int longestIncreasingSubsequence2(string text) {
	map<char, vector<int> > mp;
	map<char, int> dp;
	for (int i = 0; i < text.size(); i++) {
		mp[text[i]].push_back(i);
	}
	for (const auto &i : mp) {
		dp[i.first] = 1;
		for (const auto &j : mp) {
			if (i.first == j.first) continue;
			if (i.second[0] > j.second[0] && (i.second[0] > j.second[j.second.size() - 1])) dp[i.first] = max(dp[i.first], dp[j.first] + 1);
		}
	}
	int m = 0;
	for (const auto &i : dp)
		m = max(m, i.second);
	return m;
}
int longestIncreasingSubsequence2(string text) {
	map<char, vector<int> > mp;
	map<char, int> dp;
	for (int i = 0; i < text.size(); i++) {
		mp[text[i]].push_back(i);
	}
	for (const auto &i : mp) {
		dp[i.first] = 1;
		for (const auto &j : mp) {
			if (i.first == j.first) continue;
			if (i.second[0] > j.second[0] && (i.second[0] > j.second[j.second.size() - 1])) dp[i.first] = max(dp[i.first], dp[j.first] + 1);
		}
	}
	int m = 0;
	for (const auto &i : dp)
		m = max(m, i.second);
	return m;
}
/**
 *  Write a function to print the longest increasing sub