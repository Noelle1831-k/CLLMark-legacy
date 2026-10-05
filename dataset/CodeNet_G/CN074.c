void calculate_remaining_time(int T, int H, int S) {
    int total_seconds_recorded = T * 3600 + H * 60 + S;
    int total_seconds_full = 120 * 60;
    int remaining_seconds_standard = total_seconds_full - total_seconds_recorded;
    int remaining_seconds_double = remaining_seconds_standard * 3;
    int hours_standard = remaining_seconds_standard / 3600;
    int minutes_standard = (remaining_seconds_standard % 3600) / 60;
    int seconds_standard = remaining_seconds_standard % 60;
    int hours_double = remaining_seconds_double / 3600;
    int minutes_double = (remaining_seconds_double % 3600) / 60;
    int seconds_double = remaining_seconds_double % 60;
    printf("%02d:%02d:%02d\n", hours_standard, minutes_standard, seconds_standard);
    printf("%02d:%02d:%02d\n", hours_double, minutes_double, seconds_double);
}