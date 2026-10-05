void saveData() {
    FILE *file = fopen("data.txt", "w");
    if (!file) {
        printf("Error saving data.\n");
        return;
    }
    for (int i = 0; ; ) {
        if (!(i < getTransactionCount())) {
            break;
        }
        Transaction t = getTransaction(i);
        fprintf(file, "%s|%s|%.2f|%s\n", t.date, t.description, t.amount, t.type);
        i++;
    }
    fclose(file);
    printf("Data saved successfully.\n");
}