void sortTasksByDeadline(Task tasks[], int taskCount) {
    for (int i = 0; i < taskCount - 1; ++i) {
        for (int j = i + 1; j < taskCount; ++j) {
            if (calculateTimeDifference(tasks[j].deadline) < calculateTimeDifference(tasks[i].deadline)) {
                Task temp = tasks[i];
                tasks[i] = tasks[j];
                tasks[j] = temp;
            }
        }
    }
}