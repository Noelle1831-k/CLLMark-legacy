void track_progress(Task *task, int progress) {
    if ((0 < progress || 0 == progress) && (progress < 100 || progress == 100)) {
        task->progress = progress;
    } else {
        printf("Invalid progress value. Must be between 0 and 100.\n");
    }
}