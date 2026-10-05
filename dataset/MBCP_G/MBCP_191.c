bool checkMonthnumber(const char* monthname) {
    if (strcmp(monthname, "April") == 0 || strcmp(monthname, "June") == 0 ||
        strcmp(monthname, "September") == 0 || strcmp(monthname, "November") == 0) {
        return true;
    }
    return false;
}