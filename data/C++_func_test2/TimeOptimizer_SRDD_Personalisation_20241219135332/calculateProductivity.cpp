void TimeManager::calculateProductivity() {
    cout << "Productivity Report:\n";
    cout << "Total Tracked Time: " << totalTime << " minutes.\n";
    cout << "Total Scheduled Tasks: " << totalTasks << "\n";
    if (totalTasks > 0) {
        cout << "Average Time Per Task: " << totalTime / totalTasks << " minutes.\n";
    } else {
        cout << "No tasks scheduled yet.\n";
    }
}