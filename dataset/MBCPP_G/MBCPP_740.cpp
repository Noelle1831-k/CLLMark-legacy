unordered_map<int, int> result;
for (size_t i = 0; i < testTup.size(); i += 2) {
    result[testTup[i]] = testTup[i + 1];
}
return result;
}