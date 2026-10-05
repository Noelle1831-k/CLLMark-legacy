    string result = "";
    for (int i = 0; i < str.size(); i++) {
        for (int j = i + 1; j < str.size(); j++) {
            if (str[i] == str[j]) {
                result = str[i];
                break;
            }
        }
    }
    return result;
}