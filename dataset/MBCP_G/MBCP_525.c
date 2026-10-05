bool parallelLines(int* line1, int size1, int* line2, int size2) {
    if (size1 != size2) return false;
    if (size1 == 0) return true;
    for (int i = 1; i < size1; i++) {
        if (line1[i] * line2[0] != line2[i] * line1[0]) {
            return false;
        }
    }
    return true;
}