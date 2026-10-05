    string r = "";
    for (size_t i = 0; i < text.size(); i++) {
        if (text[i] == ' ' || text[i] == ',' || text[i] == '.') {
            r += ':';
        } else {
            r += text[i];
        }
    }
    return r;
}