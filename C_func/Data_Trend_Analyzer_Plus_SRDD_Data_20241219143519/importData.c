void importData() {
    printf("Importing data...\n");
    parseCSV("data.csv");
    printf("Data import complete. %d rows and %d columns loaded.\n", numRows, numColumns);
}