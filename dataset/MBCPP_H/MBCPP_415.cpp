    vector<int> max = {0, 0};
    for (int i = 0; i < arr.size(); i++) {
        for (int j = i + 1; j < arr.size(); j++) {
            if (arr[i] * arr[j] > max[0] * max[1]) {
                max = {arr[i], arr[j]};
            }
        }
    }
    return max;
}