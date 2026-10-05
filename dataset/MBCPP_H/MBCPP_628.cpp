    int len = str.size();
    string result = "";
    for (int i = 0; i < len; i++) {
        char ch = str[i];
        if (ch == ' ') {
            result += "%20";
        } else {
            result += ch;
        }
    }
    return result;
}