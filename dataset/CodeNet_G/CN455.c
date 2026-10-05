void calculate_time(int start_h, int start_m, int start_s, int end_h, int end_m, int end_s) {
    int total_start_seconds = start_h * 3600 + start_m * 60 + start_s;
    int total_end_seconds = end_h * 3600 + end_m * 60 + end_s;
    int total_work_seconds = total_end_seconds - total_start_seconds;
    int work_hours = total_work_seconds / 3600;
    total_work_seconds %= 3600;
    int work_minutes = total_work_seconds / 60;
    int work_seconds = total_work_seconds % 60;
    printf("%d %d %d\n", work_hours, work_minutes, work_seconds);
}