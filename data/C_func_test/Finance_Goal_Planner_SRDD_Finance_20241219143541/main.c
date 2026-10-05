int main() {
    int choice;
    while (1) {
        display_menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_goal();
                break;
            case 2:
                delete_goal();
                break;
            case 3:
                update_goal();
                check_milestone(); 
                break;
            case 4:
                add_milestone();
                break;
            case 5:
                display_progress_bar();
                break;
            case 6:
                set_reminder();
                break;
            case 7:
                check_milestone();
                break;
            case 8:
                printf("Exiting application. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}