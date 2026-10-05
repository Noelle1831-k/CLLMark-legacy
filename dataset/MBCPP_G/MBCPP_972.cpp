vector<int> result;
result.reserve(testTup1.size() + testTup2.size());
result.insert(result.end(), testTup1.begin(), testTup1.end());
result.insert(result.end(), testTup2.begin(), testTup2.end());
return result;
}