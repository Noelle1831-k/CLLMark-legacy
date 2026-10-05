vector<vector<string>> result;
vector<string> current(n);
function<void(int, int)> generate = [&](int pos, int start) {
    if (pos == n) {
        result.push_back(current);
        return;
    }
    for (int i = start; i < l.size(); ++i) {
        current[pos] = l[i];
        generate(pos + 1, i);
    }
};
generate(0, 0);
return result;
}