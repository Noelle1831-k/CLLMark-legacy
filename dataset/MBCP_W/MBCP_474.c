char* replaceChar(char* str, char* ch, char* newch) {
    char *buffer = (char *)malloc(sizeof(char) * 1024);
    char *insert_point = buffer;
    char *temp = str;
    size_t len_ch = strlen(ch);
    size_t len_newch = strlen(newch);
    while (1) {
        char *p = strstr(temp, ch);
        if (p == NULL) {
            strcpy(insert_point, temp);
            break;
        }
        memcpy(insert_point, temp, p - temp);
        insert_point += p - temp;
        memcpy(insert_point, newch, len_newch);
        insert_point += len_newch;
        temp = p + len_ch;
    }
    return buffer;
}