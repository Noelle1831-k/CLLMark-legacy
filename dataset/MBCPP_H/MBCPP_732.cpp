    char chr;
    bool isSpecial = false;
    int len = text.length();
    for (int i = 0; i < len; i++) {
        chr = text[i];
        if (chr == ' ' || chr == ',' || chr == '.' || chr == ':' || chr == '/') {
            isSpecial = true;
        }
    }
    if (!isSpecial) {
        return text;
    }
    for (int i = 0; i < len; i++) {
        chr = text[i];
        if (chr == ' ' || chr == ',' || chr == '.' || chr == ':' || chr == '/') {
            text[i] = ':';
        }
    }
    return text;
}