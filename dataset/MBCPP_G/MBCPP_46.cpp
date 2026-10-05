unordered_set<int> uniqueElements;
for (int number : data) {
    if (uniqueElements.find(number) != uniqueElements.end()) {
        return false;
    }
    uniqueElements.insert(number);
}
return true;
}