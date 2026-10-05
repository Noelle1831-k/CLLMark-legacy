int main() {
    printf("Welcome to ScheduleBuddy - Your Social Commitment Manager!\n\n");
    Scheduler *scheduler = init_scheduler();
    if (scheduler == NULL) {
        fprintf(stderr, "Failed to initialize the scheduler. Exiting program.\n");
        return 1;
    }
    while (1) {
        display_menu();
        int choice;
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            fprintf(stderr, "Invalid input. Exiting program.\n");
            break;
        }
        handle_user_input(scheduler, choice);
    }
    free_scheduler(scheduler);
    printf("Goodbye!\n");
    return 0;
}