bool sameOrder(char *l1[], int len1, char *l2[], int len2) {
    int i = 0, j = 0;
    while (i < len1 && j < len2) {
        if (strcmp(l1[i], l2[j]) == 0) {
            i++;
        }
        j++;
    }
    return i == len1;
}
