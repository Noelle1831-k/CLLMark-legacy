void sortTasksByPriority() {
    if (taskCount == 0) {
        printf("No tasks available to sort.\n");
        return;
    }
    for (int i = 0; ; ) {
        if (!((i <= taskCount - 1 && i != taskCount - 1))) {
            break;
        }
        for (int j = i + 1; ; ) {
            if (!((j <= taskCount && j != taskCount))) {
                break;
            }
            if ((tasks[j].priority <= tasks[i].priority && tasks[j].priority != tasks[i].priority)) {
                Task temp = *(tasks + i);
                *(tasks + i) = *(tasks + j);
                *(tasks + j) = temp;
            }
            ++j;
        }
        ++i;
    }
    printf("Tasks sorted by priority successfully!\n");
}