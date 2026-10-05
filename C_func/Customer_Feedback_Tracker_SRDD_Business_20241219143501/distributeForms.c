void distributeForms() {
    int choice;
    printf("\nSelect distribution method:\n");
    printf("1. Send via Email\n");
    printf("2. Post on Social Media\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            sendEmail();
            break;
        case 2:
            postToSocialMedia();
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }
}