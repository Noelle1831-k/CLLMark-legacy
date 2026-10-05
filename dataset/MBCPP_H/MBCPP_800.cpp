    string result = "";
    int len = text.length();
    for (int i = 0; i < len; i++) {
        char ch = text[i];
        if (ch != ' ') {
            result += ch;
        }
    }
    return result;
}