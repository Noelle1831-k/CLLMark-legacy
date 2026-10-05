void positionMin(int list[], int size, int result[], int *resultSize) {
    int minValue = INT_MAX;
    *resultSize = 0;
    for (int i = 0; i < size; i++) {
        if (list[i] < minValue) {
            minValue = list[i];
            *resultSize = 0;
        }
        if (list[i] == minValue) {
            result[*resultSize] = i;
            (*resultSize)++;
        }
    }
}