    string result = "";
    for (int i = 0; i < str.size(); i++) {
        if (i % 2 == 0) {
            result += str[i];
        }
    }
    return result;
}