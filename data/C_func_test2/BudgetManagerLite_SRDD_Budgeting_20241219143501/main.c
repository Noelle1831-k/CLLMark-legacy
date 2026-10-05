int main() {
    int choice;
    initialize_budget_data(); 
    do {
        display_menu();
        choice = get_integer_input("Enter your choice: ");
        execute_choice(choice);
    } while (choice != 6); 
    save_budget_data(); 
    printf("Thank you for using BudgetManagerLite. Goodbye!\n");
    return 0;
}