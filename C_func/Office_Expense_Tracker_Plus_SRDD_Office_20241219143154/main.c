int main() {
    int choice;
    while (1) {
        show_menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_expense();
                break;
            case 2:
                categorize_expense();
                break;
            case 3:
                list_expenses();
                break;
            case 4:
                set_budget();
                break;
            case 5:
                check_budget();
                break;
            case 6:
                generate_report();
                break;
            case 7:
                scan_receipt();
                break;
            case 8:
                sync_with_accounting();
                break;
            case 9:
                printf("Exiting application...\n");
                exit(0);
            default:
                printf("Invalid choice, try again.\n");
                break;
        }
    }
}