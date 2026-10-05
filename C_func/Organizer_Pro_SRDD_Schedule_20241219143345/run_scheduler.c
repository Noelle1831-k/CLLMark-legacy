void run_scheduler() {
    int choice;
    while (1) {
        show_menu();
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); 
            continue;
        }
        switch (choice) {
            case 1:
                create_task();
                break;
            case 2:
                edit_task();
                break;
            case 3:
                list_tasks();
                break;
            case 4:
                categorize_task();
                break;
            case 5:
                create_event();
                break;
            case 6:
                edit_event();
                break;
            case 7:
                list_events();
                break;
            case 8:
                set_reminder();
                break;
            case 9:
                check_reminders();
                break;
            case 10:
                generate_task_report();
                break;
            case 11:
                generate_event_report();
                break;
            case 12:
                printf("Exiting program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}