    string newStr = "";
    for (int i = 0; i < str.size(); i++) {
        char ch = str[i];
        if (ch >= 'A' && ch <= 'Z') {
            ch += 32;
        } else if (ch >= 'a' && ch <= 'z') {
            ch -= 32;
        }
        newStr += ch;
    }
    return newStr;
}