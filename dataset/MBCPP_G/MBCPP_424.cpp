vector<string> result;
for (const string& str : testTuple) {
    result.push_back(string(1, str.back()));
}
return result;
}