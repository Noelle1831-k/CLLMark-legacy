    vector<int> result = vector<int>();
    int max = list1[0];
    for (int i = 0; i < list1.size(); i++) {
        if (list1[i] > max) {
            max = list1[i];
            result = vector<int>();
        }
        if (list1[i] == max) {
            result.push_back(i);
        }
    }
    return result;
}