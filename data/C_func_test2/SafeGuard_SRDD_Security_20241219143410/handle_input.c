void handle_input(int choice) {
    switch (choice) {
        case 1:
            scan_filesystem();
            break;
        case 2:
            configure_firewall();
            break;
        case 3:
            password_manager_menu();
            break;
        case 4:
            update_virus_database();
            break;
        case 5:
            printf("Exiting SafeGuard. Stay secure!\n");
            log_event("System exited by user.");
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
            log_event("Invalid menu choice entered.");
    }
}