unordered_set<int> s;
for (int i = 0; i < n; i++) {
    if (arr[i] > 0) {
        s.insert(arr[i]);
    }
}
int missing = 1;
while (s.find(missing) != s.end()) {
    missing++;
}
return missing;
}