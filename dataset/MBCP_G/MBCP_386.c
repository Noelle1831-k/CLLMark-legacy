int swapCount(const char* s) {
    int countLeft = 0, countRight = 0;
    int swapNeeded = 0, imbalance = 0;
    while (*s) {
        if (*s == '[') {
            countLeft++;
            if (imbalance > 0) {
                swapNeeded += imbalance;
                imbalance--;
            }
        } else if (*s == ']') {
            countRight++;
            imbalance = countRight - countLeft;
        }
        s++;
    }
    return swapNeeded;
}