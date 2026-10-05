float GenreClassifier::calculateDistance(const vector<float>& a, const vector<float>& b) {
    float sum = 0.0;
    for (size_t i = 0; i < a.size(); i++) {
        sum += pow(a[i] - b[i], 2);
    }
    return sqrt(sum);
}