unordered_set<int> seen;
for (int num : testTup) {
    if (seen.find(num) != seen.end()) {
        return false;
    }
    seen.insert(num);
}
return true;
}