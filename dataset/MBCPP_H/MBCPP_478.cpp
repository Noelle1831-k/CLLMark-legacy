    string result = "";
    for (int i = 0; i < str1.size(); i++) {
        if (str1[i] >= 'A' && str1[i] <= 'Z') {
            result += str1[i];
        }
    }
    return result;
}