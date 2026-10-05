int get_input() {
    int choice;
    printf("Enter your choice: ");
    if (scanf("%d", &choice) != 1) {
        fprintf(stderr, "Error: Invalid input. Exiting.\n");
        exit(EXIT_FAILURE);  
    }
    getchar();  
    return choice;
}