map<int, int> frequency;
for(int i = 0; i < arrSize; ++i) {
    frequency[arr[i]]++;
}
for(auto &entry : frequency) {
    if(entry.second % 2 != 0) {
        return entry.first;
    }
}
return -1; // return -1 if no such element is found, though the problem guarantees there is one.
}