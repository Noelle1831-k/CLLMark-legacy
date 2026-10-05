void handle_user_choice(int choice) {
    switch (choice) {
        case 1:
            perform_scan();  
            break;
        case 2:
            enable_secure_browsing();  
            break;
        case 3:
            manage_passwords();  
            break;
        case 4:
            view_logs();  
            break;
        case 5:
            printf("Exiting SecurityGuard. Stay safe!\n");
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
    }
}