int main(int argc, char *argv[]) {
    printf("Welcome to SavingsTracker!\n");
    User user;
    create_user(&user);
    Transaction transactions[100];
    int transaction_count = 0, choice;
    SavingsGoal goal;
    set_goal(&goal, 1000); 

    do {
        printf("\nMenu:\n");
        printf("1. Add Transaction\n");
        printf("2. View Transactions\n");
        printf("3. Set Savings Goal\n");
        printf("4. View Savings Goal\n");
        printf("5. Generate Report\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                add_transaction(transactions, &transaction_count);
                break;
            case 2:
                get_transactions(transactions, transaction_count);
                break;
            case 3: {
                float target;
                printf("Enter new savings goal: ");
                scanf("%f", &target);
                set_goal(&goal, target);
                break;
            }
            case 4:
                get_goal(&goal);
                break;
            case 5:
                generate_report(transactions, transaction_count, &goal);
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 6);
    return 0;
}