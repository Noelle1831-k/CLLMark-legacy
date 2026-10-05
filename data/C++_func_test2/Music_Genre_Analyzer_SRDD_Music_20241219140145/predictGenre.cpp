string GenreClassifier::predictGenre(const vector<float>& features) {
    float minDistance = numeric_limits<float>::max();
    int bestMatchIndex = -1;
    for (size_t i = 0; i < trainingData.size(); i++) {
        float distance = calculateDistance(features, trainingData[i]);
        if (distance < minDistance) {
            minDistance = distance;
            bestMatchIndex = i;
        }
    }
    return bestMatchIndex != -1 ? trainingLabels[bestMatchIndex] : "Unknown";
}