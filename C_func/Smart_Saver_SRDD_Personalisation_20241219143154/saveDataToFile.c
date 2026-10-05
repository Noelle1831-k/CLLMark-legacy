void saveDataToFile(ExpenseList *list, char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("Error opening file for writing.\n");
        return;
    }
    Expense *current = list->head;
    while (current) {
        fprintf(file, "%s,%lf,%s\n", current->category, current->amount, current->date);
        current = current->next;
    }
    fclose(file);
}