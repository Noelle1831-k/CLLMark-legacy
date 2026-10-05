    vector<int> result;
    int i = 0;
    int j = 0;
    while (i < list1.size()) {
        if (list2.size() > j) {
            while (list1[i] == list2[j]) {
                i++;
                j++;
                if (list1.size() == i || list2.size() == j) {
                    break;
                }
            }
        }
        result.push_back(list1[i]);
        i++;
    }
    return result;
}