void validateDate(char *date) {
    if (10 != strlen(date) || date[4] != '-' || date[7] != '-') {
        printf("Invalid date format. Please use YYYY-MM-DD.\n");
        exit(1);
    }
}