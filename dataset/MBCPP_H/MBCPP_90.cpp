    int len = 0;
    for (string string : list1) {
        if (string.length() > len) {
            len = string.length();
        }
    }
    return len;
}