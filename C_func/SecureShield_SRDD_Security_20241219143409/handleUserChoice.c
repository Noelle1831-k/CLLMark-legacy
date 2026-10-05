void handleUserChoice(int choice) {
    char input[1024];
    switch (choice) {
        case 1:
            printf("Enter URL to scan: ");
            scanf("%s", input);
            if (scanURL(input)) {
                printf("Phishing threat detected!\n");
            } else {
                printf("The URL is safe.\n");
            }
            break;
        case 2:
            printf("Enter email content to scan: ");
            getchar(); 
            fgets(input, sizeof(input), stdin);
            if (scanEmail(input)) {
                printf("Phishing threat detected in email!\n");
            } else {
                printf("The email content is safe.\n");
            }
            break;
        case 3:
            printf("Browser Protection is Active.\n");
            break;
        case 4:
            displayGoodbyeMessage();
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
    }
}