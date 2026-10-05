    vector<int> result;
    int i, j;
    if (arr.size() == 1 && arr[0] == n) {
        return n;
    }
    for (i = 0; i < arr.size(); i++) {
        for (j = i + 1; j < arr.size(); j++) {
            result.push_back(abs(arr[i] - arr[j]));
        }
    }
    int min = -1;
    for (i = 0; i < result.size(); i++) {
        if (min == -1 || result[i] < min) {
            min = result[i];
        }
    }
    return min;
}