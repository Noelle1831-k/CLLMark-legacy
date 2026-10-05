vector<vector<string>> result;
transform(list1.begin(), list1.end(), back_inserter(result), [](const string &s) {
    vector<string> temp;
    for (const char &c : s) {
        temp.push_back(string(1, c));
    }
    return temp;
});
return result;
}