int main() {
    printf("Welcome to SocialMatchup!\n");
    initialize_data_store(); 
    int choice;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Create Profile\n");
        printf("2. Update Profile\n");
        printf("3. Find Matches\n");
        printf("4. Start Conversation\n");
        printf("5. Share Project Idea\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                create_profile();
                break;
            case 2:
                update_profile();
                break;
            case 3:
                match_users();
                break;
            case 4:
                send_message();
                break;
            case 5:
                share_project_idea();
                break;
            case 6:
                printf("Exiting... Thank you for using SocialMatchup!\n");
                save_data_store(); 
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}