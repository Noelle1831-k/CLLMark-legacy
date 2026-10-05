void execute_choice(int choice) {
    switch (choice) {
        case 1:
            encrypt_files();
            break;
        case 2:
            securely_delete_files();
            break;
        case 3:
            manage_passwords();
            break;
        case 4:
            block_ads_and_trackers();
            break;
        default:
            printf("Invalid choice. Please try again.\n");
    }
}