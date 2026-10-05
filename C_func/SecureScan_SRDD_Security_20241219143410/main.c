int main(int argc, char *argv[]) {
    printf("Welcome to SecureScan!\n");
    initializeUtils();
    initializeScanner();
    initializeAlerts();
    initializeScheduler();
    initializeIntegrityChecker();
    char command[256];
    while (1) {
        printf("\nEnter command (scan, schedule, check, help, exit): ");
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = 0;
        if (strcmp(command, "scan") == 0) {
            performScan();
        } else if (strcmp(command, "schedule") == 0) {
            scheduleScan();
        } else if (strcmp(command, "check") == 0) {
            checkFileIntegrity();
        } else if (strcmp(command, "help") == 0) {
            printf("Available commands:\n");
            printf("  scan     - Perform a security scan\n");
            printf("  schedule - Schedule a scan\n");
            printf("  check    - Check file integrity\n");
            printf("  help     - Display this help message\n");
            printf("  exit     - Exit the application\n");
        } else if (strcmp(command, "exit") == 0) {
            printf("Exiting SecureScan. Goodbye!\n");
            break;
        } else {
            printf("Invalid command. Please try again.\n");
        }
    }
    return 0;
}