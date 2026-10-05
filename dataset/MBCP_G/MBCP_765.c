int isPolite(int n) {
    int count = 0, i = 0;
    while (count < n) {
        i++;
        if ((i & (i - 1)) != 0) {
            count++;
        }
    }
    return i;
}