vector<int> result;
for (size_t i = 0; i < testTup.size() - 1; ++i) {
    result.push_back(testTup[i] + testTup[i + 1]);
}
return result;
}