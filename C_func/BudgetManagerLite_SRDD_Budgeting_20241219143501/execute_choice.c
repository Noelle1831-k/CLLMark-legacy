void execute_choice(int choice) {
    switch (choice) {
        case 1:
            add_expense();
            break;
        case 2:
            remove_expense();
            break;
        case 3:
            list_expenses();
            break;
        case 4:
            calculate_balance();
            break;
        case 5:
            set_income(); 
            break;
        case 6:
            break;
        default:
            printf("Invalid choice! Please try again.\n");
    }
}