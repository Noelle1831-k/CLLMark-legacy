void get_current_date() {
    time_t t;
    time(&t);
    printf("Current date and time: %s", ctime(&t));
}