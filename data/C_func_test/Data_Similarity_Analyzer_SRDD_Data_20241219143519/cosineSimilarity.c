double cosineSimilarity(const double *vecA, const double *vecB, int size) {
    double dotProduct = 0.0, magnitudeA = 0.0, magnitudeB = 0.0;
    for (int i = 0; i < size; i++) {
        dotProduct += vecA[i] * vecB[i];
        magnitudeA += vecA[i] * vecA[i];
        magnitudeB += vecB[i] * vecB[i];
    }
    return dotProduct / (sqrt(magnitudeA) * sqrt(magnitudeB));
}