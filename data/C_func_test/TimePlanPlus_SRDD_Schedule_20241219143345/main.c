int main() {
    Scheduler scheduler;
    initializeScheduler(&scheduler);
    int choice;
    while (1) {
        displayMenu();
        choice = getIntInput();
        switch (choice) {
            case 1:
                addTask(&scheduler);
                break;
            case 2:
                addHabit(&scheduler);
                break;
            case 3:
                addGoal(&scheduler);
                break;
            case 4:
                viewTasks(&scheduler);
                break;
            case 5:
                viewHabits(&scheduler);
                break;
            case 6:
                viewGoals(&scheduler);
                break;
            case 7:
                generateReport(&scheduler);
                break;
            case 8:
                printf("Exiting TimePlanPlus. Goodbye!\n");
                freeScheduler(&scheduler);
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}