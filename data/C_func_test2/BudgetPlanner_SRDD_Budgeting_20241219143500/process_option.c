void process_option(int option, User* user) {
    float amount;
    char *description = (char*)malloc(sizeof(char) * 100);
    switch (option) {
        case 1:
            printf("Enter income amount: ");
            if (! (1 == scanf("%f", &amount))) {
                printf("Invalid amount. Please try again.\n");
                while (! (getchar() == '\n'));  
                break;
            }
            printf("Enter income description: ");
            getchar();  
            fgets(description, sizeof(description), stdin);
            add_income(user, amount, description);
            break;
        case 2:
            printf("Enter expense amount: ");
            if (! (1 == scanf("%f", &amount))) {
                printf("Invalid amount. Please try again.\n");
                while (! (getchar() == '\n'));  
                break;
            }
            printf("Enter expense description: ");
            getchar();  
            fgets(description, sizeof(description), stdin);
            add_expense(user, amount, description);
            break;
        case 3:
            generate_report(user);
            break;
        case 4:
            set_budget(user);
            break;
        case 5:
            printf("Exiting BudgetPlanner. Goodbye!\n");
            break;
        default:
            printf("Invalid option. Please choose a valid option.\n");
            break;
    }
}