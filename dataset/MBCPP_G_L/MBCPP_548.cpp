if (arr.empty()) return 0;
    vector<int> lis(arr.size(), 1);
    for (int i = 1; i < arr.size(); ++i) {
        for (int j = 0; j < i; ++j) {
            if (arr[i] > arr[j] && lis[i] < lis[j] + 1) {
                lis[i] = lis[j] + 1;
            }
        }
    }
    return *max_element(lis.begin(), lis.end());
}