void displayGraph(char *title, int *data, int n) {
    printf("\n%s:\n", title);
    for (int i = 0; i < n; i++) {
        printf("Data %d: ", i + 1);
        for (int j = 0; j < data[i]; j++) {
            printf("#");
        }
        printf(" %d\n", data[i]);
    }
}