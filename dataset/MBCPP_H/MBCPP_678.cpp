    int i;
    string result = "";
    for (i = 0; i < str1.length(); i++) {
        if (str1[i] != ' ') {
            result += str1[i];
        }
    }
    return result;
}