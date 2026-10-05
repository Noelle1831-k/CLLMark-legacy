void SimilarityMatrix::generateMatrix(const vector<vector<string>>& datasets, const string& method) {
    SimilarityCalculator calculator;
    for (size_t i = 0; i < datasets.size(); ++i) {
        vector<double> row;
        for (size_t j = 0; j < datasets.size(); ++j) {
            if (method == "jaccard") {
                row.push_back(calculator.calculateJaccardSimilarity(datasets[i], datasets[j]));
            } else if (method == "cosine") {
                row.push_back(calculator.calculateCosineSimilarity(datasets[i], datasets[j]));
            }
        }
        matrix.push_back(row);
    }
}