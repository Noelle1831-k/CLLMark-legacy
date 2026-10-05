unordered_set<int> elementSet;
for (int num : testList) {
    if (elementSet.count(num)) {
        return false;
    }
    elementSet.insert(num);
}
return true;
}