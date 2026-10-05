if (seqNums.size() < 2) return "Linear Sequence";
    int diff = seqNums[1] - seqNums[0];
    for (size_t i = 1; i < seqNums.size() - 1; ++i) {
        if (seqNums[i+1] - seqNums[i] != diff) return "Non Linear Sequence";
    }
    return "Linear Sequence";
}