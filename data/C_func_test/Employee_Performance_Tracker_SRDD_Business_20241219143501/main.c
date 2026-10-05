int main() {
    int choice;
    load_data_from_file();
    while (1) {
        display_menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_employee();
                break;
            case 2:
                set_performance_goals();
                break;
            case 3:
                evaluate_performance();
                break;
            case 4:
                generate_performance_report();
                break;
            case 5:
                list_employees();
                break;
            case 6:
                save_data_to_file();
                printf("Exiting program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}