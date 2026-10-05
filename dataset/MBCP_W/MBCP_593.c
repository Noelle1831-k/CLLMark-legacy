void removezeroIp(char *ip) {
    char result[256] = "";
    char *token = strtok(ip, ".");
    int num;
    while (token != NULL) {
        num = atoi(token);
        char *temp = (char *)malloc(sizeof(char) * 4);
        sprintf(temp, "%d", num);
        strcat(result, temp);
        token = strtok(NULL, ".");
        if (token != NULL) {
            strcat(result, ".");
        }
    }
    strcpy(ip, result);
}