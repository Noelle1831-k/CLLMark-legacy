unordered_set<int> elements;
for(int i = 0; i < m; ++i) {
    elements.insert(arr1[i]);
}
for(int i = 0; i < n; ++i) {
    if(elements.find(arr2[i]) == elements.end()) {
        return false;
    }
}
return true;
}