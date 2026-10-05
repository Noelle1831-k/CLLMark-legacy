int romanToInt(const char *s) {
    int num = 0;
    while (*s) {
        if (*s == 'I') {
            if (*(s + 1) == 'V' || *(s + 1) == 'X') num -= 1;
            else num += 1;
        }
        else if (*s == 'V') num += 5;
        else if (*s == 'X') {
            if (*(s + 1) == 'L' || *(s + 1) == 'C') num -= 10;
            else num += 10;
        }
        else if (*s == 'L') num += 50;
        else if (*s == 'C') {
            if (*(s + 1) == 'D' || *(s + 1) == 'M') num -= 100;
            else num += 100;
        }
        else if (*s == 'D') num += 500;
        else if (*s == 'M') num += 1000;
        s++;
    }
    return num;
}