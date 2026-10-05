vector<int> result;
unordered_set<int> elements1(testTup1.begin(), testTup1.end());
unordered_set<int> elements2(testTup2.begin(), testTup2.end());
for (int num : testTup1) {
    if (elements2.find(num) == elements2.end()) {
        result.push_back(num);
    }
}
for (int num : testTup2) {
    if (elements1.find(num) == elements1.end()) {
        result.push_back(num);
    }
}
return result;
}