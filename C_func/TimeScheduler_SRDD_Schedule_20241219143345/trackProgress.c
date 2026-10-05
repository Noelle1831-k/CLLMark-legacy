void trackProgress() {
    if (progressCount < 100) {
        TaskProgress newProgress;
        printf("Enter task ID: ");
        scanf("%d", &newProgress.taskId);
        if (!taskExists(newProgress.taskId)) {
            printf("Error: Task ID does not exist.\n");
            return;
        }
        printf("Enter progress percentage (0-100): ");
        scanf("%d", &newProgress.progress);
        if (newProgress.progress < 0 || newProgress.progress > 100) {
            printf("Error: Progress must be between 0 and 100.\n");
            return;
        }
        progressList[progressCount++] = newProgress;
        printf("Progress tracked successfully.\n");
    } else {
        printf("Progress limit reached.\n");
    }
}