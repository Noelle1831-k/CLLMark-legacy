void drawProgressBar(int completed, int total) {
    printf("[");
    int percentage = (completed * 100) / total;
    int progress = (percentage / 5);
    for (int i = 0; i < progress; i++) {
        printf("#");
    }
    for (int i = progress; i < 20; i++) {
        printf(" ");
    }
    printf("] %d%%\n", percentage);
}