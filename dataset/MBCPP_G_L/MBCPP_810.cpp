vector<string> result;
vector<char> chars = {'p', 'q', 'r', 's'};
vector<int> counts = {a, b, c, d};
for (int i = 0; i < counts.size(); ++i) {
    for (int j = 0; j < counts[i]; ++j) {
        result.push_back(string(1, chars[i]));
    }
}
return result;
}