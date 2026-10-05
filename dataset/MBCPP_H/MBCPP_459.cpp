    string result = "";
    for (int i = 0; i < str1.size(); i++) {
        if (!isupper(str1[i])) {
            result += str1[i];
        }
    }
    return result;
}