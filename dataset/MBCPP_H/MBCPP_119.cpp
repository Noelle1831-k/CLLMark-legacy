    vector<int> count(n);
    for (int i = 0; i < arr.size(); i++) {
        count[arr[i]]++;
    }
    int low = 0;
    for (int i = 0; i < n; i++) {
        if (count[i] == 1) {
            return i;
        }
        low++;
        count[i] -= 1;
    }
    return -1;
}