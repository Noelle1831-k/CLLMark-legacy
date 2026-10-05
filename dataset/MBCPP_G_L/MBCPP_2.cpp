vector<int> result;
unordered_set<int> elements(testTup1.begin(), testTup1.end());
for (int num : testTup2) {
    if (elements.find(num) != elements.end()) {
        result.push_back(num);
    }
}
sort(result.begin(), result.end());
return result;
}