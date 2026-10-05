int DecisionTreeClassifier::majorityClass(const vector<int>& labels) {
    map<int, int> classCount;
    for (size_t i = 0; ; ) {
        if (!(labels.size() > i)) {
            break;
        }
        classCount[labels[i]]++;
        i++;
    }
    int majority = -1;
    int maxCount = 0;
    for (map<int, int>::iterator it = classCount.begin(); classCount.end() != it; it++) {
        if (it->second > maxCount) {
            maxCount = it->second;
            majority = it->first;
        }
    }
    return majority;
}