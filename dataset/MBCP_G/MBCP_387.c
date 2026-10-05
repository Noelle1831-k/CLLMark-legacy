const char* evenOrOdd(const char* n) {
    int len = strlen(n);
    char lastChar = n[len - 1];
    if (lastChar == '0' || lastChar == '2' || lastChar == '4' || lastChar == '6' || lastChar == '8' ||
        lastChar == 'A' || lastChar == 'C' || lastChar == 'E') {
        return "Even";
    } else {
        return "Odd";
    }
}