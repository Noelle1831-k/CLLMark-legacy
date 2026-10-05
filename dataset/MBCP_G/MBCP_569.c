void sortSublists(char*** list, int outerSize, int* innerSizes) {
    for (int i = 0; i < outerSize; i++) {
        for (int j = 0; j < innerSizes[i] - 1; j++) {
            for (int k = 0; k < innerSizes[i] - 1 - j; k++) {
                if (strcmp(list[i][k], list[i][k + 1]) > 0) {
                    char* temp = list[i][k];
                    list[i][k] = list[i][k + 1];
                    list[i][k + 1] = temp;
                }
            }
        }
    }
}