unordered_set<int> seen;
for (int num : arraynums) {
    if (seen.count(num) > 0) {
        return true;
    }
    seen.insert(num);
}
return false;
}