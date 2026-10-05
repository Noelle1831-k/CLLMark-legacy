int main(int argc, char *argv[]) {
    char filename[100];
    Data *data = NULL;
    int choice;
    printf("=== Welcome to Data Explorer ===\n");
    printf("Please enter the data file path (e.g., data.txt): ");
    scanf("%s", filename);
    data = loadData(filename);
    if (data == NULL) {
        printError("Failed to load data. Please check the file and try again.");
        return -1;
    }
    while (1) {
        displayMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                filterDataMenu(data);
                break;
            case 2:
                sortDataMenu(data);
                break;
            case 3:
                aggregateDataMenu(data);
                break;
            case 4:
                groupDataMenu(data);
                break;
            case 5:
                visualizeDataMenu(data);
                break;
            case 6:
                printf("Exiting application... Goodbye!\n");
                freeData(data);
                return 0;
            default:
                printError("Invalid choice. Please select a valid option.");
        }
    }
    return 0;
}