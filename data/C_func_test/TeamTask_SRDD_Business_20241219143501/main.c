int main() {
    printf("Welcome to TeamTask!\n");
    initializeUsers();
    initializeTasks();
    initializeDashboard();
    initializeFileSharing();
    initializeNotifications();
    char command[100];
    while (1) {
        printf("\nEnter command (create, assign, update, display, upload, download, notify, exit): ");
        scanf("%s", command);
        if (strcmp(command, "create") == 0) {
            createTask();
        } else if (strcmp(command, "assign") == 0) {
            assignTask();
        } else if (strcmp(command, "update") == 0) {
            updateTaskStatus();
        } else if (strcmp(command, "display") == 0) {
            displayDashboard();
        } else if (strcmp(command, "upload") == 0) {
            uploadFile();
        } else if (strcmp(command, "download") == 0) {
            downloadFile();
        } else if (strcmp(command, "notify") == 0) {
            sendNotification();
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }
    return 0;
}