set<int> elements(testTup.begin(), testTup.end());
for (int num : checkList) {
    if (elements.find(num) != elements.end()) {
        return true;
    }
}
return false;
}