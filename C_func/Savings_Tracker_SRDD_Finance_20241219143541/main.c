int main() {
    SavingsTracker tracker = {0};  
    int choice;
    float savings, target;
    char user_choice[10];
    load_data(&tracker);
    while(1) {
        display_dashboard(&tracker);
        printf("\n1. Set Savings Goal\n2. Record Savings\n3. View Savings Progress\n4. View Savings History\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); 
        switch(choice) {
            case 1:
                printf("Enter target savings amount: ");
                scanf("%f", &target);
                printf("Enter the time period in days: ");
                int days;
                scanf("%d", &days);
                set_goal(&tracker, target, days);
                break;
            case 2:
                printf("Enter the amount you want to save: ");
                scanf("%f", &savings);
                record_savings(&tracker, savings);
                break;
            case 3:
                calculate_progress(&tracker);
                display_progress_chart(&tracker);
                break;
            case 4:
                display_history(&tracker);
                display_savings_history_chart(&tracker);
                break;
            case 5:
                save_data(&tracker);
                printf("Exiting the application.\n");
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}