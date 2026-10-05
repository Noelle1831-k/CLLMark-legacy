int is_leap_year(int year) {
    if (year % 400 == 0)
        return 1;
    if (year % 100 == 0)
        return 0;
    if (year % 4 == 0)
        return 1;
    return 0;
}
void print_leap_years(int a, int b) {
    int found = 0;
    for (int year = a; year <= b; year++) {
        if (is_leap_year(year)) {
            if (found) {
                printf(" ");
            }
            printf("%d", year);
            found = 1;
        }
    }
    if (!found) {
        printf("NA");
    }
    printf("\n");
}