sort(testTup.begin(), testTup.end());
vector<int> result(testTup.begin(), testTup.begin() + k);
result.insert(result.end(), testTup.end() - k, testTup.end());
return result;
}