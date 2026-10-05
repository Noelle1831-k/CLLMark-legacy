bool checkMonthnumb(const char *monthname2) {
    const char *months_with_31_days[] = {
        "January", "March", "May", "July", "August", "October", "December"
    };
    for (int i = 0; i < 7; ++i) {
        if (strcmp(monthname2, months_with_31_days[i]) == 0) {
            return true;
        }
    }
    return false;
}