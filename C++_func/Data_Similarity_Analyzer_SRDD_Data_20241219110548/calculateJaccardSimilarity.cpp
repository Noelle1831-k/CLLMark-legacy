double SimilarityCalculator::calculateJaccardSimilarity(const vector<string>& set1, const vector<string>& set2) {
    unordered_set<string> unionSet(set1.begin(), set1.end());
    unionSet.insert(set2.begin(), set2.end());
    unordered_set<string> intersectionSet;
    for (const auto& item : set1) {
        if (find(set2.begin(), set2.end(), item) != set2.end()) {
            intersectionSet.insert(item);
        }
    }
    return static_cast<double>(intersectionSet.size()) / unionSet.size();
}