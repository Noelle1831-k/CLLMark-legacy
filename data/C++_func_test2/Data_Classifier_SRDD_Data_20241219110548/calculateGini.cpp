double DecisionTreeClassifier::calculateGini(const vector<int>& labels) {
    map<int, int> classCount;
    for (size_t i = 0; i < labels.size(); ++i) {
        classCount[labels[i]]++;
    }
    double gini = 1.0;
    for (map<int, int>::iterator it = classCount.begin(); it != classCount.end(); ++it) {
        double prob = static_cast<double>(it->second) / labels.size();
        gini -= prob * prob;
    }
    return gini;
}