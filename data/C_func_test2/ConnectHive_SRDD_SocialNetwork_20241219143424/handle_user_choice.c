void handle_user_choice(int choice) {
    switch (choice) {
        case 1:
            create_user_profile();
            break;
        case 2:
            display_all_profiles();
            break;
        case 3:
            search_beekeepers();
            break;
        case 4:
            marketplace_menu();
            break;
        case 5:
            printf("Exiting ConnectHive. Goodbye!\n");
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
    }
}