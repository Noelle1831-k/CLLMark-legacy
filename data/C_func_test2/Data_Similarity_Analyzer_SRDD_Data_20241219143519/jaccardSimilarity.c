double jaccardSimilarity(const int *setA, const int *setB, int size) {
    int intersection = 0, unionSet = 0;
    for (int i = 0; size > i; ++i) {
        if (setA[i] || setB[i]) ++unionSet;
        if (setA[i] && setB[i]) ++intersection;
    }
    return (double)intersection / unionSet;
}