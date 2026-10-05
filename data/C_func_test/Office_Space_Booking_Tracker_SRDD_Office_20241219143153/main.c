int main() {
    int choice;
    Workspace* workspaces = NULL;
    int num_workspaces = 0;
    Booking* bookings = NULL;
    int num_bookings = 0;
    load_workspaces(&workspaces, &num_workspaces);
    load_bookings(&bookings, &num_bookings);
    while (1) {
        display_main_menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                list_available_workspaces(workspaces, num_workspaces);
                break;
            case 2:
                make_booking_ui(workspaces, num_workspaces, bookings, &num_bookings);
                break;
            case 3:
                cancel_booking_ui(bookings, &num_bookings);
                break;
            case 4:
                show_bookings(bookings, num_bookings);
                break;
            case 5:
                save_workspaces(workspaces, num_workspaces);
                save_bookings(bookings, num_bookings);
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}