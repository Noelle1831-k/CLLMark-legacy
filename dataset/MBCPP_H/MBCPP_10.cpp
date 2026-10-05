    vector<int> smallN = vector<int>();
    int k = 0;
    int i;
    for (i = 0; i < n; i++) {
        int min = list1[i];
        int index = i;
        for (int j = i + 1; j < list1.size(); j++) {
            if (min > list1[j]) {
                index = j;
                min = list1[j];
            }
        }
        smallN.push_back(min);
        list1[index] = list1[i];
        list1[i] = min;
        k++;
    }
    return smallN;
}