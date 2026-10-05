int day_of_week_2004(int month, int day) {
    const char *days[] = { "Thursday", "Friday", "Saturday", "Sunday", "Monday", "Tuesday", "Wednesday" };
    int month_days[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int day_count = 0;
    for (int i = 0; i < month - 1; i++) {
        day_count += month_days[i];
    }
    day_count += day - 1;
    return day_count % 7;
}
