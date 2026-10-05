void run() {
    int choice;
    while (1) {
        printf("\n--- ShieldGuard Dashboard ---\n");
        printf("1. Start Real-Time Monitoring\n");
        printf("2. Secure Browsing\n");
        printf("3. Password Manager\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                startMonitoring();
                break;
            case 2:
                startSecureSession();
                break;
            case 3:
                passwordManagerInterface();
                break;
            case 4:
                printf("Exiting ShieldGuard. Stay safe!\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}