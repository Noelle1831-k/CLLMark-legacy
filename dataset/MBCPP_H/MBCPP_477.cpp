    int n = str.length();
    if (n == 0) return "false";
    if (n == 1) return "true";
    if (str[0] == ' ') return "true";
    int i;
    for (i = 0; i < n; i++) {
        if (str[i] > 'A' && str[i] < 'Z') {
            str[i] = str[i] + 'a' - 'A';
        }
    }
    return str;
}