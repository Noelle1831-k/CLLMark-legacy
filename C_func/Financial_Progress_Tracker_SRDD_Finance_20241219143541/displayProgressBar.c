void displayProgressBar(double progress) {
    int barWidth = 50;
    printf("[");
    int pos = barWidth * progress / 100;
    for (int i = 0; i < barWidth; ++i) {
        if (i < pos) printf("=");
        else if (i == pos) printf(">");
        else printf(" ");
    }
    printf("] %.2f%%\n", progress);
}