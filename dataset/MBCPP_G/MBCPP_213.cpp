vector<string> result;
for (size_t i = 0; i < testTup1.size(); ++i) {
    result.push_back(testTup1[i] + testTup2[i]);
}
return result;
}