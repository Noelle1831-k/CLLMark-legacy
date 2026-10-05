    int max = 0;
    vector<int> maxPair = {0, 0};
    for (int i = 0; i < arr.size(); i++) {
        for (int j = i + 1; j < arr.size(); j++) {
            if (arr[i] * arr[j] > max) {
                max = arr[i] * arr[j];
                maxPair[0] = arr[i];
                maxPair[1] = arr[j];
            }
        }
    }
    return maxPair;
}