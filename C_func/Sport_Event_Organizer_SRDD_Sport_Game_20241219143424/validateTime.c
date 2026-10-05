void validateTime(char *time) {
    if (strlen(time) != 5 || time[2] != ':') {
        printf("Invalid time format. Please use HH:MM.\n");
        exit(1);
    }
}