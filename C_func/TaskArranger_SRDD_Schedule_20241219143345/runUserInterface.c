void runUserInterface(UserInterface *ui) {
    int choice;
    while (1) {
        printf("1. Add Task\n");
        printf("2. Remove Task\n");
        printf("3. Update Task\n");
        printf("4. List Tasks\n");
        printf("5. Add Notification\n");
        printf("6. Remove Notification\n");
        printf("7. List Notifications\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if (choice == 1) {
            Task task;
            char title[100], category[50], startTime[20], endTime[20];
            int priority;
            printf("Enter title: ");
            scanf("%s", title);
            printf("Enter category: ");
            scanf("%s", category);
            printf("Enter start time: ");
            scanf("%s", startTime);
            printf("Enter end time: ");
            scanf("%s", endTime);
            printf("Enter priority: ");
            scanf("%d", &priority);
            initTask(&task, title, category, startTime, endTime, priority);
            addTask(ui->taskManager, &task);
        } else if (choice == 2) {
            int index;
            printf("Enter task index to remove: ");
            scanf("%d", &index);
            removeTask(ui->taskManager, index);
        } else if (choice == 3) {
            int index;
            Task task;
            char title[100], category[50], startTime[20], endTime[20];
            int priority;
            printf("Enter task index to update: ");
            scanf("%d", &index);
            printf("Enter new title: ");
            scanf("%s", title);
            printf("Enter new category: ");
            scanf("%s", category);
            printf("Enter new start time: ");
            scanf("%s", startTime);
            printf("Enter new end time: ");
            scanf("%s", endTime);
            printf("Enter new priority: ");
            scanf("%d", &priority);
            initTask(&task, title, category, startTime, endTime, priority);
            updateTask(ui->taskManager, index, &task);
        } else if (choice == 4) {
            listTasks(ui->taskManager);
        } else if (choice == 5) {
            int index;
            char notificationTime[20];
            printf("Enter task index to add notification: ");
            scanf("%d", &index);
            printf("Enter notification time: ");
            scanf("%s", notificationTime);
            addNotification(ui->notificationManager, &ui->taskManager->tasks[index], notificationTime);
        } else if (choice == 6) {
            int index;
            printf("Enter notification index to remove: ");
            scanf("%d", &index);
            removeNotification(ui->notificationManager, index);
        } else if (choice == 7) {
            listNotifications(ui->notificationManager);
        } else if (choice == 8) {
            break;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }
}