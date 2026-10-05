void updateTaskProgress(Task *task, int progress) {
    if (progress >= 0 && progress <= 100) {
        task->progress = progress;
    } else {
        printf("Invalid progress value. Must be between 0 and 100.\n");
    }
}