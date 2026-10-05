    string str = "";
    for (int i = 0; i < str1.size(); i++) {
        if (str1[i] != ' ') {
            str += str1[i];
        } else {
            str += chr[0];
        }
    }
    return str;
}