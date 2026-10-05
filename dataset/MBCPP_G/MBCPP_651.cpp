set<int> set1(testTup1.begin(), testTup1.end());
for (int num : testTup2) {
    if (set1.find(num) == set1.end()) {
        return false;
    }
}
return true;
}