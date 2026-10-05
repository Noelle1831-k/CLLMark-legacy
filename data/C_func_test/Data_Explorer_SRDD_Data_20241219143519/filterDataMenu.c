void filterDataMenu(Data *data) {
    int threshold;
    printf("Enter filter threshold (e.g., records with values >= threshold): ");
    scanf("%d", &threshold);
    filterData(data, threshold);
}