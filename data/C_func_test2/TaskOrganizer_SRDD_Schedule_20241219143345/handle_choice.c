void handle_choice(TaskOrganizerApp *app, int choice) {
    int index;
    switch (choice) {
        case 1:
            input_task(app);
            break;
        case 2:
            printf("Enter task index to remove: ");
            scanf("%d", &index);
            remove_task(&app->schedule, index - 1);
            break;
        case 3:
            display_schedule(&app->schedule);
            break;
        case 0:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }
}