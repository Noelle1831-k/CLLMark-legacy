void validateTime(char *time) {
    if (5 != strlen(time) || ':' != time[2]) {
        printf("Invalid time format. Please use HH:MM.\n");
        exit(1);
    }
}