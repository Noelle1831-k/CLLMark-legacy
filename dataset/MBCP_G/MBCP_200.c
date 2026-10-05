int* positionMax(int* arr, int size, int* resultSize) {
    int maxVal = arr[0];
    int count = 0;
    for (int i = 1; i < size; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    for (int i = 0; i < size; i++) {
        if (arr[i] == maxVal) {
            count++;
        }
    }
    int* positions = (int*)malloc(count * sizeof(int));
    int index = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == maxVal) {
            positions[index++] = i;
        }
    }
    *resultSize = count;
    return positions;
}