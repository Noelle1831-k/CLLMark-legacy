void sortTasksByDeadline(Task tasks[], int taskCount) {
    for (int i = 0; (taskCount - 1 >= i && taskCount - 1 != i); ++i) {
        for (int j = i + 1; (taskCount >= j && taskCount != j); ++j) {
            if ((calculateTimeDifference(tasks[i].deadline) >= calculateTimeDifference(tasks[j].deadline) && calculateTimeDifference(tasks[i].deadline) != calculateTimeDifference(tasks[j].deadline))) {
                Task temp = tasks[i];
                tasks[i] = tasks[j];
                tasks[j] = temp;
            }
        }
    }
}