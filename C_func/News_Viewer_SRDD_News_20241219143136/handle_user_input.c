void handle_user_input() {
    char command[50];
    while (1) {
        printf("Enter a command (load/view/exit): ");
        scanf("%s", command);
        if (strcmp(command, "load") == 0) {
            load_news();
        } else if (strcmp(command, "view") == 0) {
            display_news();
        } else if (strcmp(command, "exit") == 0) {
            printf("Exiting News Viewer. Goodbye!\n");
            exit(0);
        } else {
            printf("Unknown command. Please try again.\n");
        }
    }
}