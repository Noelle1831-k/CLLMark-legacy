vector<int> result;
for(size_t i = 0; i < min(testTup1.size(), testTup2.size()); ++i) {
    result.push_back(testTup1[i] & testTup2[i]);
}
return result;
}