void validateDate(char *date) {
    if (strlen(date) != 10 || date[4] != '-' || date[7] != '-') {
        printf("Invalid date format. Please use YYYY-MM-DD.\n");
        exit(1);
    }
}