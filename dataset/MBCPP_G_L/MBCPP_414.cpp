set<int> elements(list1.begin(), list1.end());
for (int num : list2) {
    if (elements.count(num)) {
        return true;
    }
}
return false;
}