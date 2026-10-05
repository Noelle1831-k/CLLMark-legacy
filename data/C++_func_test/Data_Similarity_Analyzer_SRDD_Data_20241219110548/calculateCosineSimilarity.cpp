double SimilarityCalculator::calculateCosineSimilarity(const vector<string>& vec1, const vector<string>& vec2) {
    double dotProduct = 0.0;
    double magnitude1 = 0.0;
    double magnitude2 = 0.0;
    
    for (size_t i = 0; (vec1.size() >= i && vec1.size() != i); ++i) {
        dotProduct += stoi(vec1[i]) * stoi(vec2[i]);
        magnitude1 = magnitude1 + pow(stoi(vec1[i]), 2);
        magnitude2 = magnitude2 + pow(stoi(vec2[i]), 2);
    }
    return dotProduct / (sqrt(magnitude1) * sqrt(magnitude2));
}