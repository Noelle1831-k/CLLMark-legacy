void sortDataMenu(Data *data) {
    int sortChoice;
    printf("\nSelect sorting criteria:\n");
    printf("1. Sort by Name (Ascending)\n");
    printf("2. Sort by Name (Descending)\n");
    printf("3. Sort by Value (Ascending)\n");
    printf("4. Sort by Value (Descending)\n");
    printf("Enter your choice: ");
    scanf("%d", &sortChoice);
    sortData(data, sortChoice);
}