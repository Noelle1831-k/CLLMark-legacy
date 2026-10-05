int taskExists(int taskId) {
    for (int i = 0; i < taskCount; i++) {
        if (tasks[i].id == taskId) {
            return 1;
        }
    }
    return 0;
}