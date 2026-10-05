int main() {
    int choice;
    printf("Welcome to SocialShare+\n");
    do {
        printf("\nChoose an action:\n");
        printf("1. Create Profile\n");
        printf("2. Upload Content\n");
        printf("3. Share Content\n");
        printf("4. Explore Content\n");
        printf("5. Interact with Content\n");
        printf("6. Collaborate\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: createProfile(); break;
            case 2: uploadContent(); break;
            case 3: shareContent(); break;
            case 4: exploreContent(); break;
            case 5: interactWithContent(); break;
            case 6:
                inviteCollaborator();
                provideFeedback();
                workTogether();
                break;
            case 0: printf("Exiting SocialShare+. Goodbye!\n"); break;
            default: printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);
    return 0;
}