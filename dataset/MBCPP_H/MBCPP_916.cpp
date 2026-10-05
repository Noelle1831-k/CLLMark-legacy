    vector<int> triplet = {};
    for (int i = 0; i < arrSize; i++) {
        for (int j = i + 1; j < arrSize; j++) {
            for (int k = j + 1; k < arrSize; k++) {
                if (sum == a[i] + a[j] + a[k]) {
                    triplet = {a[i], a[j], a[k]};
                    return triplet;
                }
            }
        }
    }
    return triplet;
}