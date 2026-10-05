vector<vector<int>> result;
for (size_t i = 0; i < testTup.size(); i += n) {
    vector<int> chunk;
    for (size_t j = i; j < i + n && j < testTup.size(); ++j) {
        chunk.push_back(testTup[j]);
    }
    result.push_back(chunk);
}
return result;
}