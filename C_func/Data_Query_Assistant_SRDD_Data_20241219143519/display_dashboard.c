int display_dashboard() {
    printf("\n--- Dashboard ---\n");
    printf("1. Query Dataset\n");
    printf("2. Exit\n");
    printf("Enter your choice: ");
    int choice;
    if (scanf("%d", &choice) != 1) {
        while (getchar() != '\n'); 
        return -1; 
    }
    getchar(); 
    return choice;
}