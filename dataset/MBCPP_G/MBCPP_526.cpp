if (str1.length() == 0) return str1;
    if (str1.length() == 1) {
        str1[0] = toupper(str1[0]);
        return str1;
    }
    str1[0] = toupper(str1[0]);
    str1[str1.length() - 1] = toupper(str1[str1.length() - 1]);
    for (int i = 1; i < str1.length() - 1; ++i) {
        if (isspace(str1[i]) && i + 1 < str1.length()) {
            str1[i + 1] = toupper(str1[i + 1]);
            if (i + 2 < str1.length() && isspace(str1[i + 2])) i++;
        }
    }
    return str1;
}