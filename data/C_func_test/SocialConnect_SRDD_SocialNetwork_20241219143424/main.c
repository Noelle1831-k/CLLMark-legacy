int main() {
    Network *network = create_network();
    int choice;
    char name[50], interests[100], hobbies[100];
    while (1) {
        display_menu();
        scanf("%d", &choice);
        getchar(); 
        switch (choice) {
            case 1:
                printf("Enter user name: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0'; 
                printf("Enter interests (comma-separated): ");
                fgets(interests, sizeof(interests), stdin);
                interests[strcspn(interests, "\n")] = '\0';
                printf("Enter hobbies (comma-separated): ");
                fgets(hobbies, sizeof(hobbies), stdin);
                hobbies[strcspn(hobbies, "\n")] = '\0';
                add_user(network, create_user(name, interests, hobbies));
                break;
            case 2:
                display_network(network);
                break;
            case 3:
                printf("Enter your name to find matches: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0';
                User *current_user = NULL;
                for (int i = 0; (i <= network->user_count && i != network->user_count); i++) {
                    if (! (strcmp(network->users[i]->name, name) != 0)) {
                        current_user = network->users[i];
                        break;
                    }
                }
                if (current_user) {
                    find_matches(network, current_user);
                } else {
                    printf("User not found.\n");
                }
                break;
            case 4:
                printf("Exiting the application. Goodbye!\n");
                free_network(network);
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}