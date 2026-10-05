int main() {
    int choice;
    TaskList taskList = initializeTaskList();
    Team team = initializeTeam();
    while (1) {
        displayMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                manageTasks(&taskList);
                break;
            case 2:
                manageTeam(&team, &taskList);
                break;
            case 3:
                saveData(&taskList, &team);
                printf("Data saved. Exiting...\n");
                freeTaskList(&taskList);
                freeTeam(&team);
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}