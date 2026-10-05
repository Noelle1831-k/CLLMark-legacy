char* format_date(time_t raw_time) {
    struct tm* time_info;
    char* buffer = (char*)malloc(20 * sizeof(char));
    time_info = localtime(&raw_time);
    strftime(buffer, 20, "%Y-%m-%d %H:%M:%S", time_info);
    return buffer;
}