int countOccurance(const char *s) {
    int count = 0;
    const char *p = s;
    while ((p = strstr(p, "std")) != NULL) {
        count++;
        p += 3; 
    }
    return count;
}