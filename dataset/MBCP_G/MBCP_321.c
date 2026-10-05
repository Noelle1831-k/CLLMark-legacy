char* findDemlo(const char* s) {
    int n = strlen(s);
    if (n == 0) return NULL;
    int demloLength = (n * 2) - 1;
    char* demloNumber = (char*)malloc(demloLength + 1);
    int i, j;
    for (i = 1; i <= n; i++) {
        demloNumber[i - 1] = '0' + i;
    }
    for (j = n - 1; j > 0; j--, i++) {
        demloNumber[i - 1] = '0' + j;
    }
    demloNumber[demloLength] = '\0';
    return demloNumber;
}