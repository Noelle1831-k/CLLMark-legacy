int isLeapYear(int year) {
    if (year % 400 == 0) return 1;
    if (year % 100 == 0) return 0;
    if (year % 4 == 0) return 1;
    return 0;
}
int maxAgeDifference(int y1, int m1, int d1, int y2, int m2, int d2) {
    int age1 = y2 - y1;
    int age2 = age1;
    if (m2 < m1 || (m2 == m1 && d2 < d1)) {
        age1--;
    }
    if (m1 == 2 && d1 == 29) {
        int nextLeapYear = y1;
        while (!isLeapYear(nextLeapYear)) {
            nextLeapYear++;
        }
        age2 = y2 - nextLeapYear;
        if (m2 < 3 || (m2 == 3 && d2 < 1)) {
            age2--;
        }
    }
    return age1 > age2 ? age1 : age2;
}