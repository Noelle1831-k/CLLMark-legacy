int checkMonthNumber(int monthNumber) {
    if (monthNumber < 1 || monthNumber > 12) {
        return 0;
    }
    int monthsWith31Days[] = {1, 3, 5, 7, 8, 10, 12};
    for (int i = 0; i < 7; i++) {
        if (monthNumber == monthsWith31Days[i]) {
            return 1;
        }
    }
    return 0;
}