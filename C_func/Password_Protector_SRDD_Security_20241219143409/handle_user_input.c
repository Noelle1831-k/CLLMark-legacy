void handle_user_input(char choice) {
    char site[100], password[100];
    switch (choice) {
        case '1':
            printf("Enter the site name: ");
            scanf("%99s", site);
            printf("Enter the password: ");
            scanf("%99s", password);
            save_password(site, password);
            break;
        case '2':
            printf("Enter the site name: ");
            scanf("%99s", site);
            char *retrieved_password = get_password(site);
            printf("Password for %s: %s\n", site, retrieved_password);
            free(retrieved_password);
            break;
        case '3':
            printf("Enter the site name: ");
            scanf("%99s", site);
            delete_password(site);
            break;
        case '4':
            printf("Generating a new password...\n");
            char new_password[50];
            generate_password(12, new_password);
            printf("Generated password: %s\n", new_password);
            break;
        case '5':
            printf("Syncing passwords across devices...\n");
            sync_passwords("device1", "device2");
            break;
        case '6':
            printf("Exiting...\n");
            exit(0);
            break;
        default:
            printf("Invalid choice. Please try again.\n");
    }
}