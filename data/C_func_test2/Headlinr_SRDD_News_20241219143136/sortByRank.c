void sortByRank(int *scores, int size) {
    printf("Sorting articles by rank...\n");
    for (int i = 1; i < size; i++) {
        int key = scores[i];
        int j = i - 1;
        while (j >= 0 && scores[j] < key) {
            scores[j + 1] = scores[j];
            j--;
        }
        scores[j + 1] = key;
    }
    printf("Sorting complete.\n");
}