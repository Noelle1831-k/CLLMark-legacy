    string result = "";
    for (int i = 0; i < str1.size(); i++) {
        if (str1[i] != ch[0] && str1[i] != ch[ch.size() - 1]) {
            result += str1[i];
        } else {
            result += newch;
        }
    }
    return result;
}