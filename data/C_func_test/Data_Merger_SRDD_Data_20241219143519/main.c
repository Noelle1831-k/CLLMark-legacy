int main() {
    int choice;
    char file1[256], file2[256], output_file[256];
    Dataset ds1, ds2, *merged_ds;
    while (1) {
        display_menu();
        choice = handle_user_input();
        switch (choice) {
            case 1:
                printf("Enter first file path: ");
                scanf("%255s", file1);
                if (load_file(file1, &ds1) == -1) {
                    printf("Error loading file %s\n", file1);
                    continue;
                }
                printf("Enter second file path: ");
                scanf("%255s", file2);
                if (load_file(file2, &ds2) == -1) {
                    printf("Error loading file %s\n", file2);
                    continue;
                }
                printf("Datasets loaded successfully.\n");
                break;
            case 2:
                merged_ds = merge_horizontally(&ds1, &ds2);
                if (!merged_ds) {
                    printf("Error merging datasets horizontally.\n");
                    continue;
                }
                printf("Enter output file path: ");
                scanf("%255s", output_file);
                if (save_file(output_file, merged_ds) == -1) {
                    printf("Error saving merged data to %s\n", output_file);
                } else {
                    printf("Merged data saved successfully.\n");
                }
                free(merged_ds);
                break;
            case 3:
                merged_ds = merge_vertically(&ds1, &ds2);
                if (!merged_ds) {
                    printf("Error merging datasets vertically.\n");
                    continue;
                }
                printf("Enter output file path: ");
                scanf("%255s", output_file);
                if (save_file(output_file, merged_ds) == -1) {
                    printf("Error saving merged data to %s\n", output_file);
                } else {
                    printf("Merged data saved successfully.\n");
                }
                free(merged_ds);
                break;
            case 4:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}