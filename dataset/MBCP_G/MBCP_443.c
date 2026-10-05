int largestNeg(int* list1, int size) {
    int largest = 0;
    int found = 0;
    for (int i = 0; i < size; i++) {
        if (list1[i] < 0) {
            if (!found || list1[i] > largest) {
                largest = list1[i];
                found = 1;
            }
        }
    }
    if (!found) {
        return 0; 
    }
    return largest;
}