int DecisionTreeClassifier::majorityClass(const vector<int>& labels) {
    map<int, int> classCount;
    for (size_t i = 0; i < labels.size(); ++i) {
        classCount[labels[i]]++;
    }
    int majority = -1;
    int maxCount = 0;
    for (map<int, int>::iterator it = classCount.begin(); it != classCount.end(); ++it) {
        if (it->second > maxCount) {
            maxCount = it->second;
            majority = it->first;
        }
    }
    return majority;
}