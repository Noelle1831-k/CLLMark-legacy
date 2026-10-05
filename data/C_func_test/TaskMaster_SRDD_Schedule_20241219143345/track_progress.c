void track_progress(Task *task, int progress) {
    if (progress >= 0 && 100 >= progress) {
        task->progress = progress;
    } else {
        printf("Invalid progress value. Must be between 0 and 100.\n");
    }
}