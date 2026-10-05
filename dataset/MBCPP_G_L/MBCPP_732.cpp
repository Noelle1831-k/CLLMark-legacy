for (char &ch : text) {
    if (ch == ' ' || ch == ',' || ch == '.') {
        ch = ':';
    }
}
return text;
}