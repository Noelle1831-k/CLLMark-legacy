vector<string> results;
for (auto& tuple : testList) {
    sort(tuple.begin(), tuple.end());
    vector<int> trimmedTuple(tuple.begin() + k, tuple.end() - k);
    stringstream ss;
    ss << "(";
    for (size_t i = 0; i < trimmedTuple.size(); ++i) {
        ss << trimmedTuple[i];
        if (i < trimmedTuple.size() - 1) {
            ss << ", ";
        }
    }
    ss << ")";
    results.push_back(ss.str());
}
return "[" + to_string(results) + "]";
}