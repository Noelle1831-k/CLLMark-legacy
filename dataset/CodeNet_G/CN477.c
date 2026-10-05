void calculate_time(int a, int b, int c, int d) {
    int total_seconds = a + b + c + d;
    int minutes = total_seconds / 60;
    int seconds = total_seconds % 60;
    printf("%d\n%d\n", minutes, seconds);
}