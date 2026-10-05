void executeOption(int option) {
    static int dataImported = 0;
    if (option == 1) {
        char filename[256];
        printf("Enter the filename (CSV): ");
        scanf("%s", filename);
        if (importData(filename)) {
            printf("Data imported successfully.\n");
            dataImported = 1;
        } else {
            printf("Error importing data. Check the file and try again.\n");
        }
    } else if (option == 2) {
        if (!dataImported) {
            printf("Please import data first!\n");
            return;
        }
        double mean = calculateMean();
        double median = calculateMedian();
        double mode = calculateMode();
        double range = calculateRange();
        printf("Numerical Data Summary:\n");
        printf("Mean: %.2f, Median: %.2f, Mode: %.2f, Range: %.2f\n", mean, median, mode, range);
    } else if (option == 3) {
        if (!dataImported) {
            printf("Please import data first!\n");
            return;
        }
        calculateFrequency();
        calculateDistribution();
    } else {
        printf("Invalid choice. Please try again.\n");
    }
}