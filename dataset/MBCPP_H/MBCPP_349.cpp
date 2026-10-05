    bool b = false;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '1') {
            b = true;
        }
    }
    return b ? "Yes" : "No";
}