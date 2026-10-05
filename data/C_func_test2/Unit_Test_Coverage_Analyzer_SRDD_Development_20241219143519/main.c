int main(int argc, char *argv[]) {
    int choice;
    char source_path[MAX_PATH_LENGTH];
    char test_path[MAX_PATH_LENGTH];
    while (1) {
        display_menu();
        scanf("%d", &choice);
        getchar(); 
        switch (choice) {
            case 1:
                printf("Enter the path to the source code file: ");
                fgets(source_path, MAX_PATH_LENGTH, stdin);
                source_path[strcspn(source_path, "\n")] = '\0';
                printf("Enter the path to the unit test file: ");
                fgets(test_path, MAX_PATH_LENGTH, stdin);
                test_path[strcspn(test_path, "\n")] = '\0';
                if (analyze_coverage(source_path, test_path)) {
                    printf("Coverage analysis completed successfully.\n");
                } else {
                    printf("Failed to analyze coverage. Please check the file paths.\n");
                }
                break;
            case 2:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}