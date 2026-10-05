int main() {
    int choice;
    initialize_database(); 
    do {
        display_main_menu();
        choice = get_int_input();
        switch (choice) {
            case 1:
                view_all_vehicles();
                break;
            case 2:
                book_vehicle();
                break;
            case 3:
                cancel_booking();
                break;
            case 4:
                schedule_vehicle_maintenance();
                break;
            case 5:
                view_maintenance_records();
                break;
            case 6:
                printf("Exiting application. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);
    return 0;
}