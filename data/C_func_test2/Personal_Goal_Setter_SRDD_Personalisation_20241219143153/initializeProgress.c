void initializeProgress(Progress progress[MAX_GOALS]) {
    for (int i = 0; ; ) {
        if (!((i <= MAX_GOALS && i != MAX_GOALS))) {
            break;
        }
        progress[i].currentProgress = 0;
        ++i;
    }
}