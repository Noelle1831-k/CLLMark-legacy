void printCombination(int n, int r, int index, char *data[], char *arr[], int i) {
    if (index == r) {
        for (int j = 0; j < r; j++) {
            printf("%s ", data[j]);
        }
        printf("\n");
        return;
    }
    if (i >= n) return;
    data[index] = arr[i];
    printCombination(n, r, index + 1, data, arr, i);
    printCombination(n, r, index, data, arr, i + 1);
}
void combinationsColors(char *colors[], int numColors, int r) {
    char **data = (char **)malloc(r * sizeof(char *));
    printCombination(numColors, r, 0, data, colors, 0);
    free(data);
}
