const char* seqLinear(int seqNums[], int size) {
    if (size < 2) return "Non Linear Sequence";
    int difference = seqNums[1] - seqNums[0];
    for (int i = 2; i < size; ++i) {
        if (seqNums[i] - seqNums[i - 1] != difference) {
            return "Non Linear Sequence";
        }
    }
    return "Linear Sequence";
}