void import_data() {
    char filename[100];
    printf("Enter the filename to import data: ");
    scanf("%s", filename);
    FILE *file = fopen(filename, "r");
    if (!file) {
        handle_error("Error: Unable to open file.");
        return;
    }
    parse_csv(file);
    fclose(file);
    printf("Data imported successfully. Rows: %d, Columns: %d\n", rows, cols);
}