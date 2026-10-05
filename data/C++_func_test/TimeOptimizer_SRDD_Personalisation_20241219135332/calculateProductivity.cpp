void TimeManager::calculateProductivity() {
    printf("Productivity Report:\n");
    cout << "Total Tracked Time: " << totalTime << " minutes.\n";
    cout << "Total Scheduled Tasks: " << totalTasks << "\n";
    if (totalTasks > 0) {
        cout << "Average Time Per Task: " << totalTime / totalTasks << " minutes.\n";
    } else {
        printf("No tasks scheduled yet.\n");
    }
}