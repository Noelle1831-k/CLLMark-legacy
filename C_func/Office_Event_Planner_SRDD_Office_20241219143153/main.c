int main() {
    int choice;
    while (1) {
        show_main_menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                manage_events();
                break;
            case 2:
                manage_budget();
                break;
            case 3:
                manage_tasks();
                break;
            case 4:
                manage_attendees();
                break;
            case 5:
                manage_vendors();
                break;
            case 6:
                collect_feedback();
                break;
            case 7:
                printf("Exiting the application. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}