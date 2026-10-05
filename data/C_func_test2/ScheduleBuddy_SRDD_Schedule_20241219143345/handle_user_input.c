void handle_user_input(Scheduler *scheduler, int choice) {
    if (choice == 1) {
        char name[50], date[11], time[6], description[100];
        int priority;
        printf("Enter Event Name: ");
        scanf(" %49[^\n]", name); 
        printf("Enter Date (YYYY-MM-DD): ");
        scanf("%10s", date);
        printf("Enter Time (HH:MM): ");
        scanf("%5s", time);
        printf("Enter Description: ");
        scanf(" %99[^\n]", description); 
        printf("Enter Priority (1-5): ");
        scanf("%d", &priority);
        Event *event = create_event(name, date, time, description, priority);
        if (validate_event(event)) {
            add_event(scheduler, event);
        } else {
            printf("Invalid event details provided.\n");
            free_event(event);
        }
    } else if (choice == 2) {
        list_events(scheduler);
    } else if (choice == 3) {
        sort_events(scheduler);
        printf("Events have been sorted by priority.\n");
    } else if (choice == 4) {
        exit(0);
    } else {
        printf("Invalid choice. Please try again.\n");
    }
}