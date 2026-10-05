int main() {
    Expense expenses[100];  
    int num_expenses = 0;
    char continue_program;
    printf("Welcome to the Expense Splitter Application!\n");
    do {
        int num_people = 0;
        printf("\nEnter the number of people involved in the expense: ");
        if (scanf("%d", &num_people) != 1 || num_people < 1) {
            printf("Invalid number of people. Please enter a valid number.\n");
            continue;
        }
        float total_amount = 0.0;
        printf("Enter the total expense amount: ");
        if (scanf("%f", &total_amount) != 1 || total_amount <= 0) {
            printf("Invalid amount. Please enter a positive value.\n");
            continue;
        }
        Person participants[num_people];
        get_person_details(participants, num_people);
        add_expense(expenses, &num_expenses, total_amount, participants, num_people);
        split_expenses(expenses[num_expenses - 1]);
        print_summary(expenses[num_expenses - 1]);
        printf("\nWould you like to add another expense? (y/n): ");
        getchar();  
        continue_program = getchar();
    } while (continue_program == 'y' || continue_program == 'Y');
    printf("\nThank you for using the Expense Splitter Application!\n");
    return 0;
}